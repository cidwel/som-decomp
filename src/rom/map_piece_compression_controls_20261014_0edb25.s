.setcpu "65816"
.segment "CODE"
.org $DB25
map_control_0edb25:
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
