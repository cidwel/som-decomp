.setcpu "65816"
.segment "CODE"
.org $3D65
map_control_0f3d65:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
