.setcpu "65816"
.segment "CODE"
.org $45BC
map_control_0e45bc:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
