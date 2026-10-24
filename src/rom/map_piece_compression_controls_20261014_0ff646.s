.setcpu "65816"
.segment "CODE"
.org $F646
map_control_0ff646:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
