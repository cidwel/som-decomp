.setcpu "65816"
.segment "CODE"
.org $2AA2
map_control_0e2aa2:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
