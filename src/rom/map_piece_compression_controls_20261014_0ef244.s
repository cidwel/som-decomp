.setcpu "65816"
.segment "CODE"
.org $F244
map_control_0ef244:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
