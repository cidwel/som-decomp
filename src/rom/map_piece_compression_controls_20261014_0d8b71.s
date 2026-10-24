.setcpu "65816"
.segment "CODE"
.org $8B71
map_control_0d8b71:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
