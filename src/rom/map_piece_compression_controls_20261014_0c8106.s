.setcpu "65816"
.segment "CODE"
.org $8106
map_control_0c8106:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
