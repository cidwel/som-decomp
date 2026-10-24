.setcpu "65816"
.segment "CODE"
.org $AAF3
map_control_0eaaf3:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
