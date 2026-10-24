.setcpu "65816"
.segment "CODE"
.org $12E2
map_control_0e12e2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
