.setcpu "65816"
.segment "CODE"
.org $DCF6
map_control_0edcf6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
