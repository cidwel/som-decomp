.setcpu "65816"
.segment "CODE"
.org $DB6C
map_control_0edb6c:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
