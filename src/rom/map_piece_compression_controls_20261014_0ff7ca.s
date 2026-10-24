.setcpu "65816"
.segment "CODE"
.org $F7CA
map_control_0ff7ca:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
