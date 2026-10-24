.setcpu "65816"
.segment "CODE"
.org $ED59
map_control_0fed59:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
