.setcpu "65816"
.segment "CODE"
.org $A1B4
map_control_0da1b4:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
