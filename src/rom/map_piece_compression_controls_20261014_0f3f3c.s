.setcpu "65816"
.segment "CODE"
.org $3F3C
map_control_0f3f3c:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
