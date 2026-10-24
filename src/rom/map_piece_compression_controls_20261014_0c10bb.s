.setcpu "65816"
.segment "CODE"
.org $10BB
map_control_0c10bb:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
