.setcpu "65816"
.segment "CODE"
.org $7AB9
map_control_0e7ab9:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
