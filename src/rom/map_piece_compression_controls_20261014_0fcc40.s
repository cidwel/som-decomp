.setcpu "65816"
.segment "CODE"
.org $CC40
map_control_0fcc40:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
