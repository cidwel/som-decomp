.setcpu "65816"
.segment "CODE"
.org $55EF
map_control_0e55ef:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
