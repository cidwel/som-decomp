.setcpu "65816"
.segment "CODE"
.org $92EB
map_control_0f92eb:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
