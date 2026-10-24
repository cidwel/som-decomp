.setcpu "65816"
.segment "CODE"
.org $5866
map_control_0d5866:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
