.setcpu "65816"
.segment "CODE"
.org $79AC
map_control_0f79ac:
    .byte $C4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
