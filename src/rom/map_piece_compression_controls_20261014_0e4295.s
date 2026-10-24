.setcpu "65816"
.segment "CODE"
.org $4295
map_control_0e4295:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
