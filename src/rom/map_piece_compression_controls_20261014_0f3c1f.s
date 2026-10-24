.setcpu "65816"
.segment "CODE"
.org $3C1F
map_control_0f3c1f:
    .byte $E4 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
