.setcpu "65816"
.segment "CODE"
.org $7698
map_control_0f7698:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
