.setcpu "65816"
.segment "CODE"
.org $11F7
map_control_0e11f7:
    .byte $D4 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
