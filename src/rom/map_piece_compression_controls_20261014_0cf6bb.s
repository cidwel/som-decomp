.setcpu "65816"
.segment "CODE"
.org $F6BB
map_control_0cf6bb:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
