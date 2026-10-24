.setcpu "65816"
.segment "CODE"
.org $497A
map_control_0d497a:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
