.setcpu "65816"
.segment "CODE"
.org $419D
map_control_0f419d:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
