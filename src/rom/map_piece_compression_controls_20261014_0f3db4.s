.setcpu "65816"
.segment "CODE"
.org $3DB4
map_control_0f3db4:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
