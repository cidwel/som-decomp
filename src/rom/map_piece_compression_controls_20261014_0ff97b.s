.setcpu "65816"
.segment "CODE"
.org $F97B
map_control_0ff97b:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
