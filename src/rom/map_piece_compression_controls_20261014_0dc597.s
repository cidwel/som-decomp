.setcpu "65816"
.segment "CODE"
.org $C597
map_control_0dc597:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
