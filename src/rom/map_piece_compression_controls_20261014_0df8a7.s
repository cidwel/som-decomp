.setcpu "65816"
.segment "CODE"
.org $F8A7
map_control_0df8a7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
