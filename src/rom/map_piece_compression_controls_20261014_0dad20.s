.setcpu "65816"
.segment "CODE"
.org $AD20
map_control_0dad20:
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
