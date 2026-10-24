.setcpu "65816"
.segment "CODE"
.org $479F
map_control_0f479f:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
