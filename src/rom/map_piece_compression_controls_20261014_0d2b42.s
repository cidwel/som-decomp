.setcpu "65816"
.segment "CODE"
.org $2B42
map_control_0d2b42:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
