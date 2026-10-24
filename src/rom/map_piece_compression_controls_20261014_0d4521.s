.setcpu "65816"
.segment "CODE"
.org $4521
map_control_0d4521:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
