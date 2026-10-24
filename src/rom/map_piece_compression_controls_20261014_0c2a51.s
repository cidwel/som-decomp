.setcpu "65816"
.segment "CODE"
.org $2A51
map_control_0c2a51:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
