.setcpu "65816"
.segment "CODE"
.org $862E
map_control_0c862e:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
