.setcpu "65816"
.segment "CODE"
.org $9249
map_control_0f9249:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
