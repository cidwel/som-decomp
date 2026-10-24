.setcpu "65816"
.segment "CODE"
.org $C342
map_control_0ec342:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
