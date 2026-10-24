.setcpu "65816"
.segment "CODE"
.org $8D70
map_control_0d8d70:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
