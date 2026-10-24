.setcpu "65816"
.segment "CODE"
.org $75B3
map_control_0f75b3:
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
