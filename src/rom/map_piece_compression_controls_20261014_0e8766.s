.setcpu "65816"
.segment "CODE"
.org $8766
map_control_0e8766:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
