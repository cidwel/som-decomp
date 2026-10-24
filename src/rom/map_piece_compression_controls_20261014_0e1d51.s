.setcpu "65816"
.segment "CODE"
.org $1D51
map_control_0e1d51:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
