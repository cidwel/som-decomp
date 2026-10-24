.setcpu "65816"
.segment "CODE"
.org $785B
map_control_0e785b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
