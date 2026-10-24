.setcpu "65816"
.segment "CODE"
.org $D774
map_control_0fd774:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
