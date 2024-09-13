#define T_08_HEIGHT 32
#define T_08_WIDTH 32

// array size is 3072
const int T_08[]  = {
  15, 15, 15, 29, 29, 29, 45, 45, 45, 45, 45, 45, 51, 51, 51, 45, 45, 45, 1, 1, 2, 45, 45, 45, 185, 185, 185, 198, 197, 196, 166, 166, 
  166, 186, 186, 186, 170, 170, 170, 198, 198, 197, 186, 186, 186, 175, 175, 175, 21, 21, 22, 17, 17, 17, 41, 41, 41, 17, 17, 17, 1, 1, 2, 1, 
  1, 2, 30, 30, 30, 17, 17, 17, 198, 198, 197, 175, 175, 175, 175, 175, 175, 176, 176, 176, 158, 158, 158, 186, 186, 186, 198, 198, 197, 198, 198, 197, 
  45, 45, 45, 28, 28, 28, 0, 1, 2, 45, 45, 45, 30, 30, 30, 15, 15, 15, 0, 1, 2, 17, 17, 17, 198, 197, 196, 227, 227, 227, 204, 204, 
  204, 238, 238, 238, 240, 240, 240, 240, 240, 240, 204, 204, 204, 198, 197, 196, 51, 51, 51, 36, 36, 36, 41, 41, 41, 0, 0, 1, 45, 45, 45, 15, 
  15, 15, 41, 41, 41, 0, 1, 2, 185, 185, 185, 219, 219, 219, 210, 210, 210, 204, 204, 204, 204, 204, 204, 240, 240, 240, 238, 238, 238, 186, 186, 186, 
  35, 35, 35, 28, 28, 28, 15, 15, 15, 51, 51, 51, 31, 31, 32, 15, 15, 15, 15, 15, 15, 30, 30, 30, 186, 186, 186, 255, 255, 254, 239, 239, 
  239, 219, 219, 219, 209, 209, 209, 240, 240, 240, 240, 240, 240, 186, 186, 186, 42, 42, 42, 36, 36, 36, 28, 28, 28, 17, 17, 17, 17, 17, 17, 28, 
  28, 28, 28, 28, 28, 17, 17, 17, 158, 158, 158, 238, 238, 238, 240, 240, 240, 240, 240, 240, 225, 225, 225, 225, 225, 225, 238, 238, 238, 175, 175, 175, 
  51, 51, 51, 36, 36, 36, 0, 1, 2, 17, 17, 17, 46, 46, 46, 51, 51, 51, 36, 36, 36, 41, 41, 41, 175, 175, 175, 227, 227, 227, 210, 210, 
  210, 227, 227, 227, 214, 214, 214, 220, 220, 220, 227, 227, 227, 198, 197, 196, 22, 22, 22, 17, 17, 17, 36, 36, 36, 46, 46, 47, 17, 17, 17, 17, 
  17, 17, 41, 41, 41, 0, 1, 2, 166, 166, 166, 210, 210, 210, 238, 238, 238, 210, 210, 210, 255, 254, 253, 225, 225, 225, 238, 238, 238, 186, 186, 186, 
  30, 30, 30, 45, 45, 45, 41, 41, 41, 17, 17, 17, 0, 0, 1, 1, 1, 2, 30, 30, 30, 51, 51, 51, 198, 197, 196, 238, 238, 238, 210, 210, 
  210, 238, 238, 238, 204, 204, 204, 225, 225, 225, 238, 238, 238, 170, 170, 170, 39, 39, 39, 17, 17, 17, 51, 51, 51, 28, 28, 28, 28, 28, 28, 0, 
  1, 2, 28, 28, 28, 30, 30, 30, 176, 176, 176, 225, 225, 225, 219, 219, 219, 204, 204, 204, 225, 225, 225, 204, 204, 204, 225, 225, 225, 185, 185, 185, 
  33, 33, 33, 31, 31, 31, 44, 44, 44, 34, 34, 34, 25, 25, 25, 22, 22, 22, 38, 38, 38, 19, 19, 20, 183, 184, 183, 230, 230, 230, 223, 223, 
  223, 249, 248, 248, 240, 240, 240, 204, 204, 204, 216, 216, 216, 193, 193, 193, 42, 42, 42, 16, 16, 16, 0, 1, 2, 43, 43, 43, 36, 36, 36, 29, 
  29, 29, 21, 21, 21, 16, 16, 16, 173, 173, 174, 223, 223, 223, 228, 228, 228, 226, 226, 226, 218, 218, 218, 232, 232, 232, 238, 238, 238, 173, 173, 173, 
  36, 36, 36, 30, 30, 30, 36, 36, 36, 0, 1, 2, 28, 28, 28, 0, 0, 1, 15, 15, 15, 0, 1, 2, 170, 170, 170, 227, 227, 227, 255, 255, 
  254, 210, 210, 210, 219, 219, 219, 209, 209, 209, 210, 210, 210, 175, 175, 175, 30, 30, 30, 30, 30, 30, 0, 1, 2, 30, 30, 30, 17, 17, 17, 28, 
  28, 28, 51, 51, 51, 30, 30, 30, 163, 163, 163, 240, 240, 240, 227, 227, 227, 210, 210, 210, 240, 240, 240, 210, 210, 210, 240, 240, 240, 198, 197, 196, 
  51, 51, 51, 15, 15, 15, 36, 36, 36, 45, 45, 45, 51, 51, 51, 30, 30, 31, 45, 45, 45, 51, 51, 51, 170, 170, 170, 185, 185, 185, 158, 158, 
  158, 158, 158, 158, 166, 166, 166, 186, 186, 186, 163, 163, 163, 176, 176, 176, 33, 33, 33, 17, 17, 17, 15, 15, 15, 46, 46, 46, 51, 51, 51, 36, 
  36, 36, 28, 28, 28, 1, 1, 2, 166, 166, 166, 175, 175, 175, 198, 197, 196, 170, 170, 170, 186, 186, 186, 185, 185, 185, 176, 176, 176, 158, 158, 158, 
  170, 170, 170, 158, 158, 158, 186, 186, 186, 176, 176, 176, 176, 176, 176, 186, 186, 186, 170, 170, 170, 176, 176, 176, 0, 1, 2, 46, 46, 46, 41, 41, 
  41, 30, 30, 30, 0, 1, 2, 45, 45, 45, 29, 29, 29, 36, 36, 36, 168, 168, 168, 163, 163, 163, 186, 186, 186, 198, 198, 197, 176, 176, 176, 158, 
  158, 158, 174, 174, 174, 158, 158, 158, 46, 46, 46, 51, 51, 51, 28, 28, 28, 41, 41, 41, 17, 17, 17, 15, 15, 15, 51, 51, 51, 45, 45, 46, 
  185, 185, 185, 204, 204, 204, 210, 210, 210, 210, 210, 210, 238, 238, 238, 219, 219, 219, 219, 219, 219, 170, 170, 170, 28, 28, 28, 17, 17, 17, 51, 51, 
  51, 45, 45, 45, 45, 45, 45, 0, 0, 1, 30, 30, 30, 28, 28, 28, 165, 165, 165, 255, 254, 253, 240, 240, 240, 255, 255, 254, 210, 210, 210, 225, 
  225, 225, 225, 225, 225, 175, 175, 175, 30, 30, 30, 0, 1, 2, 30, 30, 30, 36, 36, 36, 30, 30, 30, 51, 51, 51, 51, 51, 51, 51, 51, 51, 
  185, 185, 185, 204, 204, 204, 204, 204, 204, 227, 227, 227, 254, 254, 253, 204, 204, 204, 214, 214, 214, 163, 163, 162, 51, 51, 51, 41, 41, 41, 1, 0, 
  2, 17, 17, 17, 51, 51, 51, 41, 41, 41, 41, 41, 41, 17, 17, 17, 164, 164, 163, 225, 225, 225, 225, 225, 225, 227, 227, 227, 238, 238, 238, 225, 
  225, 225, 204, 204, 204, 176, 176, 176, 0, 0, 2, 51, 51, 51, 17, 17, 17, 51, 51, 51, 15, 15, 15, 51, 51, 51, 15, 15, 15, 28, 28, 28, 
  158, 158, 158, 225, 225, 225, 214, 214, 214, 225, 225, 225, 255, 255, 254, 214, 214, 214, 240, 240, 240, 170, 170, 170, 15, 15, 15, 15, 15, 15, 0, 0, 
  2, 45, 45, 45, 17, 17, 17, 46, 46, 46, 17, 17, 17, 41, 41, 41, 182, 182, 181, 209, 209, 209, 214, 214, 214, 204, 204, 204, 227, 227, 227, 210, 
  210, 210, 204, 204, 204, 175, 175, 175, 45, 45, 45, 51, 51, 51, 45, 45, 45, 51, 51, 51, 51, 51, 51, 51, 51, 51, 45, 45, 45, 36, 36, 36, 
  170, 170, 170, 204, 204, 204, 227, 227, 227, 219, 219, 219, 214, 214, 214, 210, 210, 210, 210, 210, 210, 158, 158, 158, 36, 36, 36, 15, 15, 15, 17, 17, 
  17, 41, 41, 41, 36, 36, 36, 46, 46, 46, 17, 17, 17, 36, 36, 36, 182, 182, 181, 210, 210, 210, 240, 240, 240, 209, 209, 209, 219, 219, 219, 227, 
  227, 227, 227, 227, 227, 176, 176, 176, 15, 15, 15, 36, 36, 36, 17, 17, 17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 17, 17, 17, 
  176, 176, 176, 219, 219, 219, 204, 204, 204, 240, 240, 240, 219, 219, 219, 238, 238, 238, 225, 225, 225, 158, 158, 158, 41, 41, 41, 36, 36, 36, 28, 28, 
  28, 30, 30, 30, 51, 51, 51, 51, 51, 51, 51, 51, 51, 28, 28, 28, 162, 162, 162, 204, 204, 204, 204, 204, 204, 238, 238, 238, 219, 219, 219, 255, 
  254, 253, 214, 214, 214, 158, 158, 158, 51, 51, 51, 15, 15, 15, 51, 51, 51, 30, 30, 30, 15, 15, 15, 17, 17, 17, 30, 30, 30, 15, 15, 15, 
  175, 175, 175, 227, 227, 227, 238, 238, 238, 204, 204, 204, 204, 204, 204, 255, 255, 253, 238, 238, 238, 175, 175, 175, 17, 17, 17, 15, 15, 15, 17, 17, 
  17, 45, 45, 45, 17, 17, 17, 30, 30, 30, 30, 30, 30, 41, 41, 41, 191, 191, 191, 204, 204, 204, 225, 225, 225, 209, 209, 209, 255, 254, 253, 219, 
  219, 219, 204, 204, 204, 198, 197, 196, 1, 0, 2, 28, 28, 28, 30, 30, 30, 15, 15, 15, 28, 28, 28, 17, 17, 17, 17, 17, 17, 17, 17, 17, 
  175, 175, 175, 186, 186, 186, 176, 176, 175, 198, 197, 196, 197, 197, 196, 186, 186, 186, 176, 176, 176, 158, 158, 158, 36, 36, 36, 41, 41, 41, 30, 30, 
  30, 36, 36, 36, 17, 17, 17, 0, 0, 1, 15, 15, 15, 17, 17, 17, 174, 174, 174, 198, 197, 196, 166, 166, 166, 158, 158, 158, 176, 176, 176, 185, 
  185, 185, 170, 170, 170, 198, 197, 196, 45, 45, 45, 0, 1, 2, 28, 28, 28, 51, 51, 51, 28, 28, 28, 17, 17, 17, 51, 51, 51, 45, 45, 45, 
  0, 1, 2, 28, 28, 28, 17, 17, 17, 29, 29, 29, 51, 51, 51, 30, 30, 30, 45, 45, 45, 16, 16, 16, 186, 186, 186, 158, 158, 158, 170, 170, 
  170, 185, 185, 185, 176, 176, 176, 174, 174, 174, 176, 176, 176, 175, 175, 175, 43, 43, 43, 45, 45, 45, 17, 17, 17, 41, 41, 41, 51, 51, 51, 41, 
  41, 41, 15, 15, 15, 17, 17, 17, 170, 170, 170, 197, 197, 196, 175, 175, 175, 186, 186, 186, 170, 170, 170, 186, 186, 186, 158, 158, 158, 175, 175, 175, 
  51, 51, 51, 36, 36, 36, 36, 36, 36, 28, 28, 28, 1, 1, 3, 51, 51, 51, 30, 30, 30, 36, 35, 35, 170, 170, 170, 225, 225, 225, 204, 204, 
  204, 255, 255, 254, 225, 225, 225, 225, 225, 225, 227, 227, 227, 185, 185, 185, 17, 18, 18, 15, 15, 15, 36, 36, 36, 0, 0, 1, 45, 45, 45, 35, 
  35, 35, 45, 45, 45, 51, 51, 51, 197, 197, 196, 225, 225, 225, 227, 227, 227, 210, 210, 210, 225, 225, 225, 225, 225, 225, 255, 255, 254, 175, 175, 175, 
  0, 1, 2, 30, 30, 30, 36, 36, 36, 45, 45, 45, 30, 30, 30, 30, 30, 30, 36, 36, 36, 30, 30, 30, 176, 176, 176, 227, 227, 227, 210, 210, 
  210, 238, 238, 238, 225, 225, 225, 210, 210, 210, 219, 219, 219, 158, 158, 158, 27, 27, 27, 0, 1, 2, 30, 30, 30, 28, 28, 28, 15, 15, 15, 28, 
  28, 28, 0, 0, 1, 36, 36, 36, 198, 197, 196, 225, 225, 225, 204, 204, 204, 240, 240, 240, 255, 254, 253, 255, 254, 253, 255, 255, 253, 176, 176, 176, 
  51, 51, 51, 51, 51, 51, 41, 41, 41, 30, 30, 30, 31, 30, 31, 0, 1, 2, 15, 15, 15, 36, 36, 36, 163, 163, 163, 204, 204, 204, 224, 224, 
  224, 214, 214, 214, 255, 254, 253, 241, 241, 241, 240, 240, 240, 186, 186, 186, 22, 22, 22, 17, 17, 17, 51, 51, 51, 51, 51, 51, 30, 30, 30, 51, 
  51, 51, 0, 1, 2, 30, 30, 30, 175, 175, 175, 205, 205, 205, 204, 204, 204, 219, 219, 219, 226, 226, 226, 254, 254, 253, 239, 239, 239, 170, 170, 170, 
  17, 17, 17, 15, 15, 15, 17, 17, 17, 0, 1, 2, 51, 51, 51, 28, 28, 28, 30, 30, 30, 45, 45, 45, 186, 186, 186, 238, 238, 238, 227, 227, 
  227, 219, 219, 219, 210, 210, 210, 255, 255, 254, 238, 238, 238, 158, 158, 158, 43, 43, 43, 28, 28, 28, 30, 30, 30, 37, 37, 37, 45, 45, 45, 41, 
  41, 41, 51, 51, 51, 17, 17, 17, 175, 175, 175, 225, 225, 225, 225, 225, 225, 225, 225, 225, 204, 204, 204, 204, 204, 204, 210, 210, 210, 175, 175, 175, 
  45, 45, 45, 41, 41, 41, 0, 0, 1, 30, 30, 30, 28, 28, 28, 51, 51, 51, 17, 17, 17, 29, 29, 29, 170, 170, 170, 219, 219, 219, 209, 209, 
  209, 225, 225, 225, 225, 225, 225, 255, 255, 254, 204, 204, 204, 158, 158, 158, 25, 25, 25, 28, 28, 28, 0, 1, 2, 16, 16, 16, 28, 28, 28, 45, 
  45, 45, 51, 51, 51, 30, 30, 30, 198, 197, 196, 225, 225, 225, 204, 204, 204, 227, 227, 227, 210, 210, 210, 255, 254, 253, 227, 227, 227, 185, 185, 185, 
  27, 27, 27, 31, 31, 31, 36, 36, 36, 32, 32, 32, 17, 17, 17, 4, 4, 5, 29, 29, 29, 35, 35, 35, 174, 174, 174, 220, 220, 220, 250, 250, 
  249, 240, 240, 240, 230, 230, 229, 226, 226, 226, 227, 227, 227, 171, 171, 171, 26, 26, 26, 47, 47, 47, 19, 19, 19, 37, 37, 37, 4, 4, 5, 48, 
  48, 48, 47, 47, 47, 2, 3, 3, 186, 186, 186, 212, 212, 212, 251, 251, 250, 252, 252, 251, 238, 238, 238, 249, 248, 248, 255, 254, 253, 193, 192, 192, 
  17, 17, 17, 51, 51, 51, 0, 1, 2, 36, 36, 36, 30, 30, 30, 30, 30, 30, 17, 17, 17, 15, 15, 15, 158, 158, 158, 176, 176, 176, 158, 158, 
  158, 186, 186, 186, 163, 163, 163, 158, 158, 158, 170, 170, 170, 170, 170, 170, 45, 45, 45, 41, 41, 41, 30, 30, 30, 51, 51, 51, 30, 30, 30, 0, 
  1, 2, 0, 1, 1, 41, 41, 41, 163, 163, 163, 158, 158, 158, 163, 163, 163, 175, 175, 175, 186, 186, 186, 170, 170, 170, 185, 185, 185, 158, 158, 158, 
  175, 175, 175, 185, 185, 185, 198, 197, 196, 170, 170, 170, 198, 197, 196, 158, 158, 158, 185, 185, 185, 175, 175, 175, 51, 51, 51, 41, 41, 41, 51, 51, 
  51, 51, 51, 51, 17, 17, 17, 51, 51, 51, 1, 1, 2, 30, 30, 30, 168, 168, 168, 175, 175, 175, 185, 185, 185, 176, 176, 176, 198, 197, 196, 198, 
  197, 196, 176, 176, 176, 175, 175, 175, 15, 15, 15, 36, 36, 36, 17, 17, 17, 17, 17, 17, 30, 30, 30, 15, 15, 15, 45, 45, 45, 36, 36, 36, 
  159, 159, 159, 211, 211, 211, 227, 227, 227, 204, 204, 204, 205, 205, 205, 239, 239, 239, 226, 226, 226, 159, 159, 159, 2, 2, 3, 16, 16, 16, 36, 36, 
  36, 16, 16, 16, 36, 36, 36, 17, 16, 17, 50, 50, 50, 45, 45, 45, 172, 172, 172, 220, 220, 220, 253, 253, 252, 227, 227, 227, 211, 211, 211, 210, 
  210, 210, 253, 253, 253, 174, 174, 174, 34, 34, 34, 44, 44, 44, 29, 29, 30, 17, 17, 17, 50, 50, 50, 16, 16, 16, 15, 15, 15, 15, 15, 15, 
  185, 185, 185, 219, 219, 219, 254, 254, 253, 238, 238, 238, 219, 219, 219, 254, 254, 253, 210, 210, 210, 186, 186, 186, 51, 51, 51, 51, 51, 51, 36, 36, 
  36, 17, 17, 17, 51, 51, 51, 30, 30, 30, 15, 15, 15, 45, 45, 45, 175, 175, 174, 255, 254, 254, 238, 238, 238, 240, 240, 239, 240, 240, 240, 255, 
  254, 253, 255, 255, 254, 176, 176, 176, 36, 36, 36, 30, 30, 30, 28, 28, 28, 30, 30, 30, 15, 15, 15, 36, 36, 36, 17, 17, 17, 51, 51, 51, 
  197, 197, 196, 204, 204, 204, 240, 240, 240, 210, 210, 210, 238, 239, 238, 225, 225, 225, 219, 219, 219, 167, 167, 167, 1, 1, 2, 15, 15, 15, 45, 45, 
  45, 1, 1, 2, 0, 1, 2, 29, 29, 29, 0, 1, 2, 45, 45, 45, 165, 165, 165, 226, 226, 226, 210, 210, 210, 255, 254, 253, 219, 219, 219, 227, 
  227, 227, 210, 210, 210, 170, 170, 170, 17, 17, 17, 27, 27, 27, 45, 45, 45, 30, 30, 30, 15, 15, 15, 51, 51, 51, 1, 1, 2, 15, 15, 15, 
  186, 186, 186, 238, 238, 238, 219, 219, 219, 204, 204, 204, 238, 238, 238, 220, 220, 220, 219, 219, 219, 176, 176, 175, 51, 51, 51, 17, 17, 17, 0, 0, 
  1, 51, 51, 51, 51, 51, 51, 37, 37, 37, 36, 36, 36, 45, 45, 45, 164, 164, 164, 214, 214, 214, 255, 254, 253, 211, 211, 211, 219, 219, 219, 225, 
  225, 225, 254, 255, 253, 176, 176, 176, 28, 28, 29, 17, 17, 17, 36, 36, 36, 28, 28, 28, 30, 30, 30, 29, 29, 29, 0, 0, 1, 15, 15, 15, 
  175, 175, 175, 204, 204, 204, 210, 210, 210, 204, 204, 204, 227, 227, 227, 204, 204, 204, 238, 238, 238, 198, 197, 196, 41, 41, 41, 36, 36, 36, 41, 41, 
  41, 51, 51, 51, 36, 36, 36, 28, 28, 28, 51, 51, 51, 0, 1, 2, 179, 179, 179, 210, 210, 210, 238, 238, 238, 227, 227, 227, 255, 254, 253, 214, 
  214, 214, 254, 254, 253, 163, 163, 163, 45, 45, 45, 28, 28, 28, 15, 15, 15, 15, 15, 15, 45, 45, 45, 28, 28, 28, 0, 0, 2, 15, 15, 15, 
  176, 176, 176, 227, 227, 227, 219, 219, 219, 240, 240, 240, 210, 210, 210, 219, 219, 219, 255, 254, 253, 158, 158, 158, 45, 45, 45, 41, 41, 41, 1, 1, 
  1, 28, 28, 28, 36, 36, 36, 28, 28, 28, 30, 30, 30, 17, 17, 17, 179, 179, 179, 219, 219, 219, 238, 238, 238, 239, 239, 239, 227, 227, 227, 254, 
  254, 253, 255, 254, 253, 198, 197, 196, 28, 28, 28, 51, 51, 51, 30, 30, 30, 15, 15, 15, 17, 17, 17, 30, 30, 30, 15, 15, 15, 36, 36, 36, 
  163, 163, 163, 185, 185, 185, 186, 186, 186, 158, 158, 158, 176, 176, 176, 158, 158, 158, 186, 186, 186, 198, 197, 196, 51, 51, 51, 51, 51, 51, 15, 15, 
  15, 45, 45, 45, 30, 30, 30, 17, 17, 17, 30, 30, 30, 30, 30, 30, 182, 182, 182, 170, 170, 170, 185, 185, 185, 176, 176, 176, 176, 176, 176, 175, 
  175, 175, 170, 170, 170, 185, 185, 185, 17, 17, 17, 30, 30, 30, 30, 30, 30, 30, 30, 30, 15, 15, 15, 28, 28, 28, 36, 36, 36, 0, 1, 2
};