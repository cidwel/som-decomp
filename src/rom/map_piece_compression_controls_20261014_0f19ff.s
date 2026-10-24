.setcpu "65816"
.segment "CODE"
.org $19FF
map_control_0f19ff:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
