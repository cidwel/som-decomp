.setcpu "65816"
.segment "CODE"
.org $197D
map_control_0e197d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
