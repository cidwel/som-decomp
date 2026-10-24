.setcpu "65816"
.segment "CODE"
.org $63E6
map_control_0c63e6:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $48 ; distance low bit/count
