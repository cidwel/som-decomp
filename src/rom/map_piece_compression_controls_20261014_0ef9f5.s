.setcpu "65816"
.segment "CODE"
.org $F9F5
map_control_0ef9f5:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
