.setcpu "65816"
.segment "CODE"
.org $B6EF
map_control_0eb6ef:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
