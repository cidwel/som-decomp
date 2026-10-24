.setcpu "65816"
.segment "CODE"
.org $372E
map_control_0d372e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
