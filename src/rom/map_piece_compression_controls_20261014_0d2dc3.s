.setcpu "65816"
.segment "CODE"
.org $2DC3
map_control_0d2dc3:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
