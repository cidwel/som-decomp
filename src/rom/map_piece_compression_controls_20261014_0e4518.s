.setcpu "65816"
.segment "CODE"
.org $4518
map_control_0e4518:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
