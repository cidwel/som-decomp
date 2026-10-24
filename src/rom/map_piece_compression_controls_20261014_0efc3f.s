.setcpu "65816"
.segment "CODE"
.org $FC3F
map_control_0efc3f:
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
