.setcpu "65816"
.segment "CODE"
.org $70AC
map_control_0e70ac:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
