.setcpu "65816"
.segment "CODE"
.org $E3A5
map_control_0de3a5:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
