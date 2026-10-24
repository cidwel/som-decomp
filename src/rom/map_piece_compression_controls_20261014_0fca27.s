.setcpu "65816"
.segment "CODE"
.org $CA27
map_control_0fca27:
    .byte $C4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E7 ; previous-row copy count
