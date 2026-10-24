.setcpu "65816"
.segment "CODE"
.org $E9FD
map_control_0de9fd:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
