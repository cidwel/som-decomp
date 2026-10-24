.setcpu "65816"
.segment "CODE"
.org $F591
map_control_0cf591:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
