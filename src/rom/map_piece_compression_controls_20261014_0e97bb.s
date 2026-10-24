.setcpu "65816"
.segment "CODE"
.org $97BB
map_control_0e97bb:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
