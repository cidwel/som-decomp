.setcpu "65816"
.segment "CODE"
.org $55F1
map_control_0f55f1:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
