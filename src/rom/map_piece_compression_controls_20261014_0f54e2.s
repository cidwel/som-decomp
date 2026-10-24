.setcpu "65816"
.segment "CODE"
.org $54E2
map_control_0f54e2:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
