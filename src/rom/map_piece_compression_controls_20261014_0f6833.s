.setcpu "65816"
.segment "CODE"
.org $6833
map_control_0f6833:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
