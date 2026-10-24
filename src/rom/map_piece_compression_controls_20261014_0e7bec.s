.setcpu "65816"
.segment "CODE"
.org $7BEC
map_control_0e7bec:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
