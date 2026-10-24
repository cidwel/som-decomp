.setcpu "65816"
.segment "CODE"
.org $C070
map_control_0fc070:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
