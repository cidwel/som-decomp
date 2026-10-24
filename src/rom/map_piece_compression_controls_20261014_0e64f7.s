.setcpu "65816"
.segment "CODE"
.org $64F7
map_control_0e64f7:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
