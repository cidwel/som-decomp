.setcpu "65816"
.segment "CODE"
.org $B65B
map_control_0eb65b:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
