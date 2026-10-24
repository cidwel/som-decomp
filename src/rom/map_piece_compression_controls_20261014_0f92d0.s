.setcpu "65816"
.segment "CODE"
.org $92D0
map_control_0f92d0:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
