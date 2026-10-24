.setcpu "65816"
.segment "CODE"
.org $B3C6
map_control_0eb3c6:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
