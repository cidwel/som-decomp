.setcpu "65816"
.segment "CODE"
.org $5F08
map_control_0f5f08:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
