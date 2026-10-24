.setcpu "65816"
.segment "CODE"
.org $64CF
map_control_0f64cf:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
