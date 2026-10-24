.setcpu "65816"
.segment "CODE"
.org $0598
map_control_0f0598:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
