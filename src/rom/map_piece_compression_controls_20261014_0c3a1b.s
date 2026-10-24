.setcpu "65816"
.segment "CODE"
.org $3A1B
map_control_0c3a1b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
