.setcpu "65816"
.segment "CODE"
.org $05CA
map_control_0f05ca:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
