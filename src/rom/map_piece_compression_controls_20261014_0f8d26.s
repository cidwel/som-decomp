.setcpu "65816"
.segment "CODE"
.org $8D26
map_control_0f8d26:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
