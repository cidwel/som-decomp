.setcpu "65816"
.segment "CODE"
.org $2E1B
map_control_0c2e1b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
