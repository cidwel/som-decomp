.setcpu "65816"
.segment "CODE"
.org $3AA8
map_control_0f3aa8:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
