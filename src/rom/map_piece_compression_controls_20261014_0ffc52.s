.setcpu "65816"
.segment "CODE"
.org $FC52
map_control_0ffc52:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
