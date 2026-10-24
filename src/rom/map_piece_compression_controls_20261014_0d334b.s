.setcpu "65816"
.segment "CODE"
.org $334B
map_control_0d334b:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
