.setcpu "65816"
.segment "CODE"
.org $DB54
map_control_0edb54:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
