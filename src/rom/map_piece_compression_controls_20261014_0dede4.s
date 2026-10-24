.setcpu "65816"
.segment "CODE"
.org $EDE4
map_control_0dede4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
