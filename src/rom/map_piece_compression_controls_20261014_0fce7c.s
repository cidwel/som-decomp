.setcpu "65816"
.segment "CODE"
.org $CE7C
map_control_0fce7c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
