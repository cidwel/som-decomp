.setcpu "65816"
.segment "CODE"
.org $7FD9
map_control_0d7fd9:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
