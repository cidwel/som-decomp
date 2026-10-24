.setcpu "65816"
.segment "CODE"
.org $FC21
map_control_0efc21:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
