.setcpu "65816"
.segment "CODE"
.org $59D9
map_control_0d59d9:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
