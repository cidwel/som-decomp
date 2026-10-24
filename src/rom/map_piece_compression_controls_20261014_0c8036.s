.setcpu "65816"
.segment "CODE"
.org $8036
map_control_0c8036:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
