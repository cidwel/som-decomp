.setcpu "65816"
.segment "CODE"
.org $7D48
map_control_0e7d48:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
