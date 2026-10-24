.setcpu "65816"
.segment "CODE"
.org $547F
map_control_0c547f:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
