.setcpu "65816"
.segment "CODE"
.org $7FD6
map_control_0c7fd6:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
