.setcpu "65816"
.segment "CODE"
.org $68C6
map_control_0c68c6:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
