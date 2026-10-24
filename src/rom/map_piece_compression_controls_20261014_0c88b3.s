.setcpu "65816"
.segment "CODE"
.org $88B3
map_control_0c88b3:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
