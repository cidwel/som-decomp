.setcpu "65816"
.segment "CODE"
.org $63FF
map_control_0f63ff:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
