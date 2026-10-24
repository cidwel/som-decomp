.setcpu "65816"
.segment "CODE"
.org $0424
map_control_0f0424:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
