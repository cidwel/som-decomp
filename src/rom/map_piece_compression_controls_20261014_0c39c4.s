.setcpu "65816"
.segment "CODE"
.org $39C4
map_control_0c39c4:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
