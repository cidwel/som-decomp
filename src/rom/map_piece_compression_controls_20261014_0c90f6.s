.setcpu "65816"
.segment "CODE"
.org $90F6
map_control_0c90f6:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
