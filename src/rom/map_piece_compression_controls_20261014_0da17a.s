.setcpu "65816"
.segment "CODE"
.org $A17A
map_control_0da17a:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
