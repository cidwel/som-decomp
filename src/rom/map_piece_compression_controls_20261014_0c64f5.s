.setcpu "65816"
.segment "CODE"
.org $64F5
map_control_0c64f5:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
