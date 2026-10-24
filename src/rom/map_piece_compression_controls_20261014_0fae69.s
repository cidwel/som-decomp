.setcpu "65816"
.segment "CODE"
.org $AE69
map_control_0fae69:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
