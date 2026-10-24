.setcpu "65816"
.segment "CODE"
.org $8826
map_control_0c8826:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
