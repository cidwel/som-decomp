.setcpu "65816"
.segment "CODE"
.org $A4F1
map_control_0fa4f1:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
