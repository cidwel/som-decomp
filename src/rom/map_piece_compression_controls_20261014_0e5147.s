.setcpu "65816"
.segment "CODE"
.org $5147
map_control_0e5147:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
