.setcpu "65816"
.segment "CODE"
.org $22C4
map_control_0e22c4:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
