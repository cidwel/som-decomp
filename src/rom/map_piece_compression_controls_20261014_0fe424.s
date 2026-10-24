.setcpu "65816"
.segment "CODE"
.org $E424
map_control_0fe424:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
