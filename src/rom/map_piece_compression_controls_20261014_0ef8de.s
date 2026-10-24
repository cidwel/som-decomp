.setcpu "65816"
.segment "CODE"
.org $F8DE
map_control_0ef8de:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
