.setcpu "65816"
.segment "CODE"
.org $34E2
map_control_0e34e2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
