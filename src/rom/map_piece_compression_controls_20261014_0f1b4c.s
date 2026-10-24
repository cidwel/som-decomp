.setcpu "65816"
.segment "CODE"
.org $1B4C
map_control_0f1b4c:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $59 ; distance low bit/count
