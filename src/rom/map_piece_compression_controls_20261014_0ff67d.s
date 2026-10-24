.setcpu "65816"
.segment "CODE"
.org $F67D
map_control_0ff67d:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
