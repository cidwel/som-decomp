.setcpu "65816"
.segment "CODE"
.org $BC2E
map_control_0dbc2e:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
