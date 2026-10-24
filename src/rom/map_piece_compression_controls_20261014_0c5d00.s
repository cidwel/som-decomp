.setcpu "65816"
.segment "CODE"
.org $5D00
map_control_0c5d00:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
