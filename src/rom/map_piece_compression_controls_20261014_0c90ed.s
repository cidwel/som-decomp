.setcpu "65816"
.segment "CODE"
.org $90ED
map_control_0c90ed:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
