.setcpu "65816"
.segment "CODE"
.org $CA4C
map_control_0fca4c:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E6 ; previous-row copy count
