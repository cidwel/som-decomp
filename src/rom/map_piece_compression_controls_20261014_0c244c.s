.setcpu "65816"
.segment "CODE"
.org $244C
map_control_0c244c:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
