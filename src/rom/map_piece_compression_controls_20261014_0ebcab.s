.setcpu "65816"
.segment "CODE"
.org $BCAB
map_control_0ebcab:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $35 ; distance low bit/count
