.setcpu "65816"
.segment "CODE"
.org $CBF2
map_control_0fcbf2:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
