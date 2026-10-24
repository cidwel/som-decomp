.setcpu "65816"
.segment "CODE"
.org $61A5
map_control_0d61a5:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
