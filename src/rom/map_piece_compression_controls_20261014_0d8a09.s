.setcpu "65816"
.segment "CODE"
.org $8A09
map_control_0d8a09:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
