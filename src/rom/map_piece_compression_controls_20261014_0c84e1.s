.setcpu "65816"
.segment "CODE"
.org $84E1
map_control_0c84e1:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
