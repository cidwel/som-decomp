.setcpu "65816"
.segment "CODE"
.org $5CC0
map_control_0f5cc0:
    .byte $CF ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $0B ; distance low bit/count
