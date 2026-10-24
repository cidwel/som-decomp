.setcpu "65816"
.segment "CODE"
.org $1DEA
map_control_0f1dea:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
