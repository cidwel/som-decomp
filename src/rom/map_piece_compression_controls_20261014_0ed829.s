.setcpu "65816"
.segment "CODE"
.org $D829
map_control_0ed829:
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
