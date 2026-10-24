.setcpu "65816"
.segment "CODE"
.org $9788
map_control_0f9788:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
