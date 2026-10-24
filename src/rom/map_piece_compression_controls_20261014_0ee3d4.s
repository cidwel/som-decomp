.setcpu "65816"
.segment "CODE"
.org $E3D4
map_control_0ee3d4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
