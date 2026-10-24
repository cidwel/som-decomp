.setcpu "65816"
.segment "CODE"
.org $B3D6
map_control_0fb3d6:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
