.setcpu "65816"
.segment "CODE"
.org $33FF
map_control_0f33ff:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
