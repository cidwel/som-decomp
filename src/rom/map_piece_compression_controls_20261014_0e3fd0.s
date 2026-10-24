.setcpu "65816"
.segment "CODE"
.org $3FD0
map_control_0e3fd0:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E7 ; previous-row copy count
