.setcpu "65816"
.segment "CODE"
.org $C77E
map_control_0fc77e:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
