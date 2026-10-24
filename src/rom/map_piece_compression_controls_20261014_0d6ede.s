.setcpu "65816"
.segment "CODE"
.org $6EDE
map_control_0d6ede:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
