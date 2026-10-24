.setcpu "65816"
.segment "CODE"
.org $130A
map_control_0c130a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
