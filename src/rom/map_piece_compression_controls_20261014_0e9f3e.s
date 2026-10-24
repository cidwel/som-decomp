.setcpu "65816"
.segment "CODE"
.org $9F3E
map_control_0e9f3e:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
