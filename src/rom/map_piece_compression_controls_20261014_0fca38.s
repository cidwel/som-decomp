.setcpu "65816"
.segment "CODE"
.org $CA38
map_control_0fca38:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
