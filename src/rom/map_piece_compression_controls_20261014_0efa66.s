.setcpu "65816"
.segment "CODE"
.org $FA66
map_control_0efa66:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
