.setcpu "65816"
.segment "CODE"
.org $1A56
; Four native FIR presets, eight signed coefficients each.
; SPC $150C; physical ROM $C31A56. Native132F uses (C7 &3)*8.
filter_0:
.byte 127, 0, 0, 0, 0, 0, 0, 0
filter_1:
.byte 12, 33, 43, 43, 19, (-2) & $FF, (-13) & $FF, (-7) & $FF
filter_2:
.byte 88, (-65) & $FF, (-37) & $FF, (-16) & $FF, (-2) & $FF, 7, 12, 12
filter_3:
.byte 52, 51, 0, (-39) & $FF, (-27) & $FF, 1, (-4) & $FF, (-21) & $FF
