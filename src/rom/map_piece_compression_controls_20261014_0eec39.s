.setcpu "65816"
.segment "CODE"
.org $EC39
map_control_0eec39:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
