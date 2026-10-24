.setcpu "65816"
.segment "CODE"
.org $5B5C
map_control_0d5b5c:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
