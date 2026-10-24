.setcpu "65816"
.segment "CODE"
.org $650A
map_control_0f650a:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $72 ; row-distance/count
