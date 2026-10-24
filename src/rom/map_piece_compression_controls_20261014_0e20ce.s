.setcpu "65816"
.segment "CODE"
.org $20CE
map_control_0e20ce:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
