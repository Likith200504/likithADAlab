#include <stdio.h>

int n = 5;
int p[10] = {3, 3, 2, 5, 1};  // weights
int w[10] = {10, 15, 10, 12, 8}; // values
int W = 10;  // capacity

int main() {
    int cur_w;
    float tot_v = 0;  // initialize total value
    int i, maxi;
    int used[10];

    // Mark all items as unused
    for (i = 0; i < n; ++i)
        used[i] = 0;

    cur_w = W;

    while (cur_w > 0) {
        maxi = -1;

        // Find item with highest value-to-weight ratio that hasn't been used
        for (i = 0; i < n; ++i) {
            if (used[i] == 0 &&
                (maxi == -1 || (float)w[i] / p[i] > (float)w[maxi] / p[maxi])) {
                maxi = i;
            }
        }

        used[maxi] = 1;
        cur_w -= p[maxi];
        tot_v += w[maxi];

        if (cur_w >= 0) {
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n",
                   maxi + 1, w[maxi], p[maxi], cur_w);
        } else {
            // Fractionally add the item
            float fraction = 1 + (float)cur_w / p[maxi];
            printf("Added %d%% (%d, %d) of object %d in the bag.\n",
                   (int)(fraction * 100), w[maxi], p[maxi], maxi + 1);

            tot_v -= w[maxi];
            tot_v += fraction * w[maxi];
        }
    }

    printf("Filled the bag with objects worth %.2f.\n", tot_v);
    return 0;
}
