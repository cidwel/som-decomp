.setcpu "65816"
.segment "CODE"
.org $51B7
map_control_0d51b7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
