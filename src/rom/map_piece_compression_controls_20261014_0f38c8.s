.setcpu "65816"
.segment "CODE"
.org $38C8
map_control_0f38c8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
