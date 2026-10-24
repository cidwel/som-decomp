.setcpu "65816"
.segment "CODE"
.org $F5B4
map_control_0df5b4:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
