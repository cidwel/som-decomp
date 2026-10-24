.setcpu "65816"
.segment "CODE"
.org $DA41
map_control_0dda41:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
