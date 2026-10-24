.setcpu "65816"
.segment "CODE"
.org $1A50
map_control_0e1a50:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
