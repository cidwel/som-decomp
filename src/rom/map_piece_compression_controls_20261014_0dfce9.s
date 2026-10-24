.setcpu "65816"
.segment "CODE"
.org $FCE9
map_control_0dfce9:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
