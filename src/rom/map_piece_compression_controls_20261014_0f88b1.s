.setcpu "65816"
.segment "CODE"
.org $88B1
map_control_0f88b1:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
