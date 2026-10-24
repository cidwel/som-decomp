.setcpu "65816"
.segment "CODE"
.org $3987
map_control_0c3987:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
