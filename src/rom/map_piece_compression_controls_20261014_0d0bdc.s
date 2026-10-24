.setcpu "65816"
.segment "CODE"
.org $0BDC
map_control_0d0bdc:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
