.setcpu "65816"
.segment "CODE"
.org $E5B6
map_control_0de5b6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
