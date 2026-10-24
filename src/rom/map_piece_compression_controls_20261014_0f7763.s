.setcpu "65816"
.segment "CODE"
.org $7763
map_control_0f7763:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
