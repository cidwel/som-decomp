.setcpu "65816"
.segment "CODE"
.org $B6D1
map_control_0eb6d1:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
