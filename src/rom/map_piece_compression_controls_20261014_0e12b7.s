.setcpu "65816"
.segment "CODE"
.org $12B7
map_control_0e12b7:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
