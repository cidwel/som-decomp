.setcpu "65816"
.segment "CODE"
.org $7849
map_control_0c7849:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
