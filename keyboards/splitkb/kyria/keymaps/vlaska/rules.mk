# Space optimization
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
ENCODER_ENABLE = no       # Enables the use of one or more encoders
MUSIC_ENABLE = no
UNICODE_ENABLE = no
SWAP_HANDS_ENABLE = no

# Screen
OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays

# RGB lights
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

# Keyboard configuration
AUTO_SHIFT_ENABLE = no
KEY_LOCK_ENABLE = no
DEBOUNCE_TYPE = asym_eager_defer_pk
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

SRC += vlaska.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tapdances.c
endif
