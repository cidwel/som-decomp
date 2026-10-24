.setcpu "65816"
.segment "CODE"
.org $D793
map_control_0ed793:
    .byte $E5 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
