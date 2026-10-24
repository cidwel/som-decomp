.setcpu "65816"
.segment "CODE"
.org $39E4
map_control_0c39e4:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
