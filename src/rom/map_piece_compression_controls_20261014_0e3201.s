.setcpu "65816"
.segment "CODE"
.org $3201
map_control_0e3201:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
