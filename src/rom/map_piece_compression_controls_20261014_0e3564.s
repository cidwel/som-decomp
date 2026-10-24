.setcpu "65816"
.segment "CODE"
.org $3564
map_control_0e3564:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
