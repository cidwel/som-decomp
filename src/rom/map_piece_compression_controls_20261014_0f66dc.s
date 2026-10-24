.setcpu "65816"
.segment "CODE"
.org $66DC
map_control_0f66dc:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
