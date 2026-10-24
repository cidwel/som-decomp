.setcpu "65816"
.segment "CODE"
.org $231A
map_control_0e231a:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
