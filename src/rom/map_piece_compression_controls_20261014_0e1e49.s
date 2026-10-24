.setcpu "65816"
.segment "CODE"
.org $1E49
map_control_0e1e49:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
