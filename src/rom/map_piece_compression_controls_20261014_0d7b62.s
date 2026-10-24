.setcpu "65816"
.segment "CODE"
.org $7B62
map_control_0d7b62:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
