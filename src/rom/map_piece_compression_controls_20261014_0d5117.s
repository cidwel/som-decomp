.setcpu "65816"
.segment "CODE"
.org $5117
map_control_0d5117:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
