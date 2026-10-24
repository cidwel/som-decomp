.setcpu "65816"
.segment "CODE"
.org $5B40
map_control_0d5b40:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
