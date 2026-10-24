.setcpu "65816"
.segment "CODE"
.org $44AC
map_control_0e44ac:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
