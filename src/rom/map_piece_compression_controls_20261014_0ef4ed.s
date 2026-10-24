.setcpu "65816"
.segment "CODE"
.org $F4ED
map_control_0ef4ed:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
