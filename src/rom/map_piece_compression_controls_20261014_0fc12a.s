.setcpu "65816"
.segment "CODE"
.org $C12A
map_control_0fc12a:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
