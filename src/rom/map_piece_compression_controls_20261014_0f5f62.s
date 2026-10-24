.setcpu "65816"
.segment "CODE"
.org $5F62
map_control_0f5f62:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
