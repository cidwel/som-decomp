.setcpu "65816"
.segment "CODE"
.org $D260
map_control_0fd260:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
