.setcpu "65816"
.segment "CODE"
.org $F9DC
map_control_0ef9dc:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
