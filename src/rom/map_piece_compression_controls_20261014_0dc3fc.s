.setcpu "65816"
.segment "CODE"
.org $C3FC
map_control_0dc3fc:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
