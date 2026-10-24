.setcpu "65816"
.segment "CODE"
.org $45AA
map_control_0f45aa:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
