.setcpu "65816"
.segment "CODE"
.org $DB03
map_control_0edb03:
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
