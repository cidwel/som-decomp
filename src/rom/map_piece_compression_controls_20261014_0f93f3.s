.setcpu "65816"
.segment "CODE"
.org $93F3
map_control_0f93f3:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
