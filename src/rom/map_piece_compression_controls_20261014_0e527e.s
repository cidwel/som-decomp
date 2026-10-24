.setcpu "65816"
.segment "CODE"
.org $527E
map_control_0e527e:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
