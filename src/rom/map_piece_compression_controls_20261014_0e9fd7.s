.setcpu "65816"
.segment "CODE"
.org $9FD7
map_control_0e9fd7:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
