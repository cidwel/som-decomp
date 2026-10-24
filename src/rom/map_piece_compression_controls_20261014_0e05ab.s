.setcpu "65816"
.segment "CODE"
.org $05AB
map_control_0e05ab:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
