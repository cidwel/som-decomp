.setcpu "65816"
.segment "CODE"
.org $C19E
map_control_0ec19e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
