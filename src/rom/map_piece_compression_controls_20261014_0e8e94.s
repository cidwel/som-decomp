.setcpu "65816"
.segment "CODE"
.org $8E94
map_control_0e8e94:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
