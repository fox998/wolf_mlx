
#ifndef KEYS_H
# define KEYS_H

# ifdef __APPLE__
#  define ESC 53
#  define RIGHT_ERROW 123
#  define LEFT_ERROW 124
#  define UP_ERROW 126
#  define DOWN_ERROW 125
#  define MINUS 78
#  define PLUS 69
#  define ONE 18
#  define TWO 19
#  define Q_KEY 12
#  define W_KEY 13
#  define E_KEY 14
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define SPASE 49
# else
#  define ESC 65307
#  define RIGHT_ERROW 65363
#  define LEFT_ERROW 65361
#  define UP_ERROW 65362
#  define DOWN_ERROW 65364
#  define MINUS 65453
#  define PLUS 65451
#  define ONE 49
#  define TWO 50
#  define Q_KEY 1738
#  define W_KEY 1731
#  define E_KEY 1749
#  define A_KEY 1734
#  define S_KEY 1753
#  define D_KEY 1751
#  define SPASE 32
#  define M_LEFT 1
#  define M_RIGT 3
# endif

#endif