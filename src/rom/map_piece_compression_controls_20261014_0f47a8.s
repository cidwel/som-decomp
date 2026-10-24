.setcpu "65816"
.segment "CODE"
.org $47A8
map_control_0f47a8:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
