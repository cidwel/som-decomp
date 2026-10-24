.setcpu "65816"
.segment "CODE"
.org $CA19
map_control_0fca19:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
