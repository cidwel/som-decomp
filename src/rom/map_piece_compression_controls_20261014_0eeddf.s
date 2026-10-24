.setcpu "65816"
.segment "CODE"
.org $EDDF
map_control_0eeddf:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
