.setcpu "65816"
.segment "CODE"
.org $EF28
map_control_0eef28:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
