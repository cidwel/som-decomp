.setcpu "65816"
.segment "CODE"
.org $3AE1
map_control_0c3ae1:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
