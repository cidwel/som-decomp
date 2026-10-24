.setcpu "65816"
.segment "CODE"
.org $759C
map_control_0e759c:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
