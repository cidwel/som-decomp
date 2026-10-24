.setcpu "65816"
.segment "CODE"
.org $BC57
map_control_0fbc57:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
