.setcpu "65816"
.segment "CODE"
.org $204A
map_control_0e204a:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
