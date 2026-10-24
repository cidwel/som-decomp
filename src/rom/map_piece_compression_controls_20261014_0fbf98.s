.setcpu "65816"
.segment "CODE"
.org $BF98
map_control_0fbf98:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
