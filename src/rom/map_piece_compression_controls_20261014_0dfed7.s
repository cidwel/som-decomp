.setcpu "65816"
.segment "CODE"
.org $FED7
map_control_0dfed7:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
