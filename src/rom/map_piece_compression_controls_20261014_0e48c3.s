.setcpu "65816"
.segment "CODE"
.org $48C3
map_control_0e48c3:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
