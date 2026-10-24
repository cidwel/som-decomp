.setcpu "65816"
.segment "CODE"
.org $9312
map_control_0f9312:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
