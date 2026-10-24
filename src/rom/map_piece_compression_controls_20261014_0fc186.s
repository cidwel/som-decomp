.setcpu "65816"
.segment "CODE"
.org $C186
map_control_0fc186:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
