.setcpu "65816"
.segment "CODE"
.org $3567
map_control_0f3567:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
