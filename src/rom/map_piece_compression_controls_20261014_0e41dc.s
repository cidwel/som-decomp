.setcpu "65816"
.segment "CODE"
.org $41DC
map_control_0e41dc:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
