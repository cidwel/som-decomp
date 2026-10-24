.setcpu "65816"
.segment "CODE"
.org $4F6C
map_control_0e4f6c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
