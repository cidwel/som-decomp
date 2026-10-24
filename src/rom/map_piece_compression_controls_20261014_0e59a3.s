.setcpu "65816"
.segment "CODE"
.org $59A3
map_control_0e59a3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
