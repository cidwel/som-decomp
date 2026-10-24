.setcpu "65816"
.segment "CODE"
.org $768E
map_control_0e768e:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
