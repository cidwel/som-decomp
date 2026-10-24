.setcpu "65816"
.segment "CODE"
.org $680B
map_control_0c680b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
