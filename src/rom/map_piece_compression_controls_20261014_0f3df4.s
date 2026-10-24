.setcpu "65816"
.segment "CODE"
.org $3DF4
map_control_0f3df4:
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
