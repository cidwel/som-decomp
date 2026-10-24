.setcpu "65816"
.segment "CODE"
.org $C4B8
map_control_0fc4b8:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
