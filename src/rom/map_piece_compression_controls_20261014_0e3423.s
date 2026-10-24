.setcpu "65816"
.segment "CODE"
.org $3423
map_control_0e3423:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
