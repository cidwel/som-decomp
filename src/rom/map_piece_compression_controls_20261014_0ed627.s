.setcpu "65816"
.segment "CODE"
.org $D627
map_control_0ed627:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
