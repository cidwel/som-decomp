.setcpu "65816"
.segment "CODE"
.org $3D71
map_control_0c3d71:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
