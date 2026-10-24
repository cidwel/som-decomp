.setcpu "65816"
.segment "CODE"
.org $DB72
map_control_0fdb72:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
