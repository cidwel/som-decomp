.setcpu "65816"
.segment "CODE"
.org $537D
map_control_0f537d:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
