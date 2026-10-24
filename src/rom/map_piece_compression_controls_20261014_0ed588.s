.setcpu "65816"
.segment "CODE"
.org $D588
map_control_0ed588:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
