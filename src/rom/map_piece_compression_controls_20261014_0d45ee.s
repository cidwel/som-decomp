.setcpu "65816"
.segment "CODE"
.org $45EE
map_control_0d45ee:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
