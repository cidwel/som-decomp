.setcpu "65816"
.segment "CODE"
.org $6C19
map_control_0e6c19:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
