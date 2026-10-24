.setcpu "65816"
.segment "CODE"
.org $A1EB
map_control_0da1eb:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
