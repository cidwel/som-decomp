.setcpu "65816"
.segment "CODE"
.org $6C25
map_control_0d6c25:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
