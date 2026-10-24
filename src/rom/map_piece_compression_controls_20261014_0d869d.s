.setcpu "65816"
.segment "CODE"
.org $869D
map_control_0d869d:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
