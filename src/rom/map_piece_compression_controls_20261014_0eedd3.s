.setcpu "65816"
.segment "CODE"
.org $EDD3
map_control_0eedd3:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
