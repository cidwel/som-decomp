.setcpu "65816"
.segment "CODE"
.org $E079
map_control_0fe079:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
