.setcpu "65816"
.segment "CODE"
.org $8CAE
map_control_0f8cae:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
