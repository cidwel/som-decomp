.setcpu "65816"
.segment "CODE"
.org $5240
map_control_0e5240:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E1 ; previous-row copy count
