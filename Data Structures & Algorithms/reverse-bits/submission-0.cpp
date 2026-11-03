class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = n;
        // 0000
        for (int i = 0; i < 16; ++i) {
            uint32_t low = (ans & (0x1 << i)) >> i;
            uint32_t upper = (ans & (0x1 << (31 - i))) >> (31 - i);
            ans &= ~(0x1 << (31 - i)) & 0xFFFFFFFF;
            ans |= (low << (31 - i));
            ans &= ~(0x1 << i) & 0xFFFFFFFF;
            ans |= (upper << i);
        }
        return ans;
    }
};
