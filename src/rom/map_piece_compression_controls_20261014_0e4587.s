.setcpu "65816"
.segment "CODE"
.org $4587
map_control_0e4587:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
