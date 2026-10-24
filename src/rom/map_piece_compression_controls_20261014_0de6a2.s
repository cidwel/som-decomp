.setcpu "65816"
.segment "CODE"
.org $E6A2
map_control_0de6a2:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
