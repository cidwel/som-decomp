.setcpu "65816"
.segment "CODE"
.org $74F6
map_control_0e74f6:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
