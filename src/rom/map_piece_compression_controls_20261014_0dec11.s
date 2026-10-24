.setcpu "65816"
.segment "CODE"
.org $EC11
map_control_0dec11:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
