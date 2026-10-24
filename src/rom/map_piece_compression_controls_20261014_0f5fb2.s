.setcpu "65816"
.segment "CODE"
.org $5FB2
map_control_0f5fb2:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
