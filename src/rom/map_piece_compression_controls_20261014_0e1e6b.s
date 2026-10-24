.setcpu "65816"
.segment "CODE"
.org $1E6B
map_control_0e1e6b:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
