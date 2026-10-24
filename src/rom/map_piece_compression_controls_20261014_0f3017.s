.setcpu "65816"
.segment "CODE"
.org $3017
map_control_0f3017:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
