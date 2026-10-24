.setcpu "65816"
.segment "CODE"
.org $14B4
map_control_0c14b4:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
