.setcpu "65816"
.segment "CODE"
.org $2A11
map_control_0c2a11:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
