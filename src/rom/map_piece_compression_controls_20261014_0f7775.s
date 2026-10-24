.setcpu "65816"
.segment "CODE"
.org $7775
map_control_0f7775:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
