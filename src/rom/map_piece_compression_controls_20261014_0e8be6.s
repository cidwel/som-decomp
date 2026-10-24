.setcpu "65816"
.segment "CODE"
.org $8BE6
map_control_0e8be6:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
