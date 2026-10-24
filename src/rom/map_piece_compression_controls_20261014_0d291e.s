.setcpu "65816"
.segment "CODE"
.org $291E
map_control_0d291e:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
