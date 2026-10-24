.setcpu "65816"
.segment "CODE"
.org $B3D0
map_control_0db3d0:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
