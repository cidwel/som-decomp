.setcpu "65816"
.segment "CODE"
.org $E300
map_control_0de300:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6A ; row-distance/count
