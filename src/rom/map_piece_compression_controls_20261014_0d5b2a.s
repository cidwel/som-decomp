.setcpu "65816"
.segment "CODE"
.org $5B2A
map_control_0d5b2a:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
