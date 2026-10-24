.setcpu "65816"
.segment "CODE"
.org $EDD3
map_control_0dedd3:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
