.setcpu "65816"
.segment "CODE"
.org $4329
map_control_0e4329:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
