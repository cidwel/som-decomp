.setcpu "65816"
.segment "CODE"
.org $F729
map_control_0ff729:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
