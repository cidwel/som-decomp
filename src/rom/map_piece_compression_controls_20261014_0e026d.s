.setcpu "65816"
.segment "CODE"
.org $026D
map_control_0e026d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
