.setcpu "65816"
.segment "CODE"
.org $24DC
map_control_0e24dc:
    .byte $F5 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
