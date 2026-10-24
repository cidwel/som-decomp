.setcpu "65816"
.segment "CODE"
.org $7ECB
map_control_0c7ecb:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
