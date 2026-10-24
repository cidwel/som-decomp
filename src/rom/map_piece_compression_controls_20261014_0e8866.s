.setcpu "65816"
.segment "CODE"
.org $8866
map_control_0e8866:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
