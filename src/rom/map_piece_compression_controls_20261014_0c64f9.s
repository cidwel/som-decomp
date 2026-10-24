.setcpu "65816"
.segment "CODE"
.org $64F9
map_control_0c64f9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
