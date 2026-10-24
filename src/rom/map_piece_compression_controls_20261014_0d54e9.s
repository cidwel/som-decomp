.setcpu "65816"
.segment "CODE"
.org $54E9
map_control_0d54e9:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
