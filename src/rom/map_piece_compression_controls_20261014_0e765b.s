.setcpu "65816"
.segment "CODE"
.org $765B
map_control_0e765b:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
