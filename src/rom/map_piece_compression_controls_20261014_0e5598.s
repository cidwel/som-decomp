.setcpu "65816"
.segment "CODE"
.org $5598
map_control_0e5598:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
