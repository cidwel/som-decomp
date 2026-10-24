.setcpu "65816"
.segment "CODE"
.org $3C2E
map_control_0e3c2e:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
