.setcpu "65816"
.segment "CODE"
.org $0C89
map_control_0e0c89:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
