.setcpu "65816"
.segment "CODE"
.org $2204
map_control_0d2204:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
