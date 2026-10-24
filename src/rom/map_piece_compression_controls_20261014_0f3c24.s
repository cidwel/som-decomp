.setcpu "65816"
.segment "CODE"
.org $3C24
map_control_0f3c24:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
