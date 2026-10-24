.setcpu "65816"
.segment "CODE"
.org $DF61
map_control_0edf61:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
