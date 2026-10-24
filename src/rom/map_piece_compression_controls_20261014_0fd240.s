.setcpu "65816"
.segment "CODE"
.org $D240
map_control_0fd240:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
