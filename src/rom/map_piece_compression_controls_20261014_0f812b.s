.setcpu "65816"
.segment "CODE"
.org $812B
map_control_0f812b:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
