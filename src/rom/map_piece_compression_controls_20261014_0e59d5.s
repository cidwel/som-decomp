.setcpu "65816"
.segment "CODE"
.org $59D5
map_control_0e59d5:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
