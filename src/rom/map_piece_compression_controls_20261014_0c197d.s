.setcpu "65816"
.segment "CODE"
.org $197D
map_control_0c197d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
