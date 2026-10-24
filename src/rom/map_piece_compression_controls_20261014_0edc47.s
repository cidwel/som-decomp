.setcpu "65816"
.segment "CODE"
.org $DC47
map_control_0edc47:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
