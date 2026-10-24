.setcpu "65816"
.segment "CODE"
.org $0CF3
map_control_0c0cf3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
