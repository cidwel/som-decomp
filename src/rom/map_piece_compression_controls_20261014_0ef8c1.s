.setcpu "65816"
.segment "CODE"
.org $F8C1
map_control_0ef8c1:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
