.setcpu "65816"
.segment "CODE"
.org $7513
map_control_0d7513:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
