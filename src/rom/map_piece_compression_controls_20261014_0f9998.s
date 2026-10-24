.setcpu "65816"
.segment "CODE"
.org $9998
map_control_0f9998:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
