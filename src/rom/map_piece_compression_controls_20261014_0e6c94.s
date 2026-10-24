.setcpu "65816"
.segment "CODE"
.org $6C94
map_control_0e6c94:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
