.setcpu "65816"
.segment "CODE"
.org $BA8F
map_control_0dba8f:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
