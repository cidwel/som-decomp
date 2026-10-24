.setcpu "65816"
.segment "CODE"
.org $7834
map_control_0e7834:
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
