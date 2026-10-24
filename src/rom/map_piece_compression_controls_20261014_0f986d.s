.setcpu "65816"
.segment "CODE"
.org $986D
map_control_0f986d:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
