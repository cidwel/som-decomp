.setcpu "65816"
.segment "CODE"
.org $12B2
map_control_0e12b2:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
