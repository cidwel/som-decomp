.setcpu "65816"
.segment "CODE"
.org $7302
map_control_0f7302:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
