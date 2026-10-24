.setcpu "65816"
.segment "CODE"
.org $6232
map_control_0e6232:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
