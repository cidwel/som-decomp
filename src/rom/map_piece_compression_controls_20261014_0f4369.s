.setcpu "65816"
.segment "CODE"
.org $4369
map_control_0f4369:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
