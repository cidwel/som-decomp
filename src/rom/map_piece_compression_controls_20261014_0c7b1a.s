.setcpu "65816"
.segment "CODE"
.org $7B1A
map_control_0c7b1a:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
