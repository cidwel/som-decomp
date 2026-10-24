.setcpu "65816"
.segment "CODE"
.org $3004
map_control_0f3004:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
