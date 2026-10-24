.setcpu "65816"
.segment "CODE"
.org $64F0
map_control_0e64f0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
