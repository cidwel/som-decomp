.setcpu "65816"
.segment "CODE"
.org $0DE4
map_control_0e0de4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
