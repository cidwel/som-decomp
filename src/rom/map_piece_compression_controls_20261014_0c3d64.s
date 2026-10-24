.setcpu "65816"
.segment "CODE"
.org $3D64
map_control_0c3d64:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
