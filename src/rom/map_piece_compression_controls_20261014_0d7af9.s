.setcpu "65816"
.segment "CODE"
.org $7AF9
map_control_0d7af9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
