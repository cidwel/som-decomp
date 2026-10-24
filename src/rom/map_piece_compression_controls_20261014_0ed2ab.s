.setcpu "65816"
.segment "CODE"
.org $D2AB
map_control_0ed2ab:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
