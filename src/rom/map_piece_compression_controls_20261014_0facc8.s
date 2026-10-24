.setcpu "65816"
.segment "CODE"
.org $ACC8
map_control_0facc8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
