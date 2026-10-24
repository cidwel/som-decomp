.setcpu "65816"
.segment "CODE"
.org $C32D
map_control_0ec32d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
