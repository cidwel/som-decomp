.setcpu "65816"
.segment "CODE"
.org $C597
map_control_0ec597:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
