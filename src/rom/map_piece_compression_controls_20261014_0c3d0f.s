.setcpu "65816"
.segment "CODE"
.org $3D0F
map_control_0c3d0f:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
