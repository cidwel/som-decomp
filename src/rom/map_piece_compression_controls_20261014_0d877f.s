.setcpu "65816"
.segment "CODE"
.org $877F
map_control_0d877f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
