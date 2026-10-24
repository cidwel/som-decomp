.setcpu "65816"
.segment "CODE"
.org $84B1
map_control_0c84b1:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
