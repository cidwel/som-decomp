.setcpu "65816"
.segment "CODE"
.org $BBBD
map_control_0fbbbd:
    .byte $E2 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
