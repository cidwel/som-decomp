.setcpu "65816"
.segment "CODE"
.org $2059
map_control_0c2059:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
