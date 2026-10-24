.setcpu "65816"
.segment "CODE"
.org $FDD4
map_control_0dfdd4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
