.setcpu "65816"
.segment "CODE"
.org $901D
map_control_0e901d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
