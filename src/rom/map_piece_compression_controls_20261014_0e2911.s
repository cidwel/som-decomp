.setcpu "65816"
.segment "CODE"
.org $2911
map_control_0e2911:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
