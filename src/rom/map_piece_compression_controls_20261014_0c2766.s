.setcpu "65816"
.segment "CODE"
.org $2766
map_control_0c2766:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
