.setcpu "65816"
.segment "CODE"
.org $EA8E
map_control_0eea8e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
