.setcpu "65816"
.segment "CODE"
.org $2A65
map_control_0e2a65:
    .byte $E0 ; previous-row copy escape
    .byte $76 ; row-distance/count
