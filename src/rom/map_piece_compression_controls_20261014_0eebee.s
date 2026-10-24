.setcpu "65816"
.segment "CODE"
.org $EBEE
map_control_0eebee:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
