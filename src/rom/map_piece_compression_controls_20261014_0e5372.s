.setcpu "65816"
.segment "CODE"
.org $5372
map_control_0e5372:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
