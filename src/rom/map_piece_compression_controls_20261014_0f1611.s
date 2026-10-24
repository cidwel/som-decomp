.setcpu "65816"
.segment "CODE"
.org $1611
map_control_0f1611:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
