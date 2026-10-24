.setcpu "65816"
.segment "CODE"
.org $7E1B
map_control_0c7e1b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
