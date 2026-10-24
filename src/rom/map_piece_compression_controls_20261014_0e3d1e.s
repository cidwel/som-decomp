.setcpu "65816"
.segment "CODE"
.org $3D1E
map_control_0e3d1e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
