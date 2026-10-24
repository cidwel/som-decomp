.setcpu "65816"
.segment "CODE"
.org $1515
map_control_0f1515:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
