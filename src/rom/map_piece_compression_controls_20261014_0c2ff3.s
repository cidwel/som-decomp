.setcpu "65816"
.segment "CODE"
.org $2FF3
map_control_0c2ff3:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
