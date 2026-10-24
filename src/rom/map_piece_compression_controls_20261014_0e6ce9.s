.setcpu "65816"
.segment "CODE"
.org $6CE9
map_control_0e6ce9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
