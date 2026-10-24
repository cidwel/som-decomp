.setcpu "65816"
.segment "CODE"
.org $B578
map_control_0db578:
    .byte $CF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
