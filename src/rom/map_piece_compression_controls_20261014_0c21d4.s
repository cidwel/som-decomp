.setcpu "65816"
.segment "CODE"
.org $21D4
map_control_0c21d4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
