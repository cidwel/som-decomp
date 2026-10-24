.setcpu "65816"
.segment "CODE"
.org $BFF4
map_control_0fbff4:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
