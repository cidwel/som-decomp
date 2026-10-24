.setcpu "65816"
.segment "CODE"
.org $7AE2
map_control_0f7ae2:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
