.setcpu "65816"
.segment "CODE"
.org $F61B
map_control_0ef61b:
    .byte $EE ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
