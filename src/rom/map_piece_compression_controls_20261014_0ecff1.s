.setcpu "65816"
.segment "CODE"
.org $CFF1
map_control_0ecff1:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
