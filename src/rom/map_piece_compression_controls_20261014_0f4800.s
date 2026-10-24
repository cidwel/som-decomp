.setcpu "65816"
.segment "CODE"
.org $4800
map_control_0f4800:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
