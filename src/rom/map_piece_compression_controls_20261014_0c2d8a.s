.setcpu "65816"
.segment "CODE"
.org $2D8A
map_control_0c2d8a:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
