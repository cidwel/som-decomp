.setcpu "65816"
.segment "CODE"
.org $96AA
map_control_0d96aa:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
