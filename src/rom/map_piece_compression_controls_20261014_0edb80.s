.setcpu "65816"
.segment "CODE"
.org $DB80
map_control_0edb80:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
