.setcpu "65816"
.segment "CODE"
.org $12FF
map_control_0f12ff:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
