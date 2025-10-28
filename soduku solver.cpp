//SODUKU SOLVER
#include <bits/stdc++.h>
using namespace std;

struct Pos { int r, c; };

static inline int box_id(int r, int c) { return (r/3)*3 + (c/3); }
static inline int bit_of(int d) { return 1 << (d - 1); }

struct Sudoku {
    array<int,9> row{}, col{}, box{};         // bitmasks of used digits
    vector<vector<char>> board{9, vector<char>(9, '.')};
    vector<Pos> empties;

    void init_masks() {
        row.fill(0); col.fill(0); box.fill(0);
        empties.clear();
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') { empties.push_back({r,c}); continue; }
                int d = ch - '0', b = box_id(r,c), m = bit_of(d);
                row[r] |= m; col[c] |= m; box[b] |= m;
            }
        }
    }

    int candidates_mask(int r, int c) const {
        int used = row[r] | col[c] | box[box_id(r,c)];
        return (~used) & 0x1FF;               // Why: 9 bits for digits 1..9
    }

    int pick_mrv_index() const {
        int best_i = -1, best_cnt = 10;
        for (int i = 0; i < (int)empties.size(); ++i) {
            auto [r,c] = empties[i];
            if (board[r][c] != '.') continue; // already filled earlier in recursion
            int mask = candidates_mask(r,c);
            int cnt = __builtin_popcount(mask);
            if (cnt < best_cnt) { best_cnt = cnt; best_i = i; if (cnt == 1) break; }
        }
        return best_i;
    }

    bool dfs() {
        int idx = pick_mrv_index();
        if (idx == -1) return true;          // solved
        int r = empties[idx].r, c = empties[idx].c;
        int mask = candidates_mask(r,c);
        if (mask == 0) return false;         // dead end

        while (mask) {
            int bit = mask & -mask;          // lowest set bit
            int d = __builtin_ctz(bit) + 1;  // digit 1..9
            // place
            board[r][c] = char('0' + d);
            row[r] |= bit; col[c] |= bit; box[box_id(r,c)] |= bit;

            if (dfs()) return true;

            // undo
            board[r][c] = '.';
            row[r] &= ~bit; col[c] &= ~bit; box[box_id(r,c)] &= ~bit;

            mask &= mask - 1;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: any stream containing exactly 81 relevant chars among '1'..'9' or '.'
    // e.g., 9 lines of 9 chars, or the LeetCode-style JSON array; non-relevant chars are ignored.
    Sudoku s;
    int filled = 0;
    while (filled < 81) {
        int ch = cin.get();
        if (ch == EOF) break;
        if ((ch >= '1' && ch <= '9') || ch == '.') {
            int r = filled / 9, c = filled % 9;
            s.board[r][c] = static_cast<char>(ch);
            ++filled;
        }
    }
    if (filled != 81) return 0;              // malformed input guard

    s.init_masks();
    bool ok = s.dfs();
    if (!ok) return 0;

    // Output: 9 lines of 9 chars
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) cout << s.board[r][c];
        cout << '\n';
    }
    return 0;
}
