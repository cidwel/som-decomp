.setcpu "65816"
.segment "CODE"
.org $453A
map_control_0c453a:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
