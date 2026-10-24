.setcpu "65816"
.segment "CODE"
.org $3A60
map_control_0c3a60:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
