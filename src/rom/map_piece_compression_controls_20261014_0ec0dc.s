.setcpu "65816"
.segment "CODE"
.org $C0DC
map_control_0ec0dc:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
