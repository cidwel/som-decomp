.setcpu "65816"
.segment "CODE"
.org $A1B8
map_control_0da1b8:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
