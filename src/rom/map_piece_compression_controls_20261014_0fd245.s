.setcpu "65816"
.segment "CODE"
.org $D245
map_control_0fd245:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
