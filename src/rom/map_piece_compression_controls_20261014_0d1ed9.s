.setcpu "65816"
.segment "CODE"
.org $1ED9
map_control_0d1ed9:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
