.setcpu "65816"
.segment "CODE"
.org $AAF3
map_control_0daaf3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
