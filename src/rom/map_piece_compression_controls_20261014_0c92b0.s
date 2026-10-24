.setcpu "65816"
.segment "CODE"
.org $92B0
map_control_0c92b0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
