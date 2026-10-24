.setcpu "65816"
.segment "CODE"
.org $249A
map_control_0f249a:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
