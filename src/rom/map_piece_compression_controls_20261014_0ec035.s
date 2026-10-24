.setcpu "65816"
.segment "CODE"
.org $C035
map_control_0ec035:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
