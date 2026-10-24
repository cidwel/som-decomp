.setcpu "65816"
.segment "CODE"
.org $12FF
map_control_0e12ff:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
