.setcpu "65816"
.segment "CODE"
.org $F11E
map_control_0df11e:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
