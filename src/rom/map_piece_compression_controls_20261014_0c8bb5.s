.setcpu "65816"
.segment "CODE"
.org $8BB5
map_control_0c8bb5:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
