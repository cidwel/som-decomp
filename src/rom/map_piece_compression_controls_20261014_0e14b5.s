.setcpu "65816"
.segment "CODE"
.org $14B5
map_control_0e14b5:
    .byte $E0 ; previous-row copy escape
    .byte $64 ; row-distance/count
