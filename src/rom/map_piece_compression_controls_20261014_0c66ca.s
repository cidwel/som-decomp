.setcpu "65816"
.segment "CODE"
.org $66CA
map_control_0c66ca:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
