.setcpu "65816"
.segment "CODE"
.org $1D43
map_control_0d1d43:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
