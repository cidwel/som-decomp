.setcpu "65816"
.segment "CODE"
.org $2419
map_control_0e2419:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
