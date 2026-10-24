.setcpu "65816"
.segment "CODE"
.org $19C4
map_control_0c19c4:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
