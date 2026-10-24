.setcpu "65816"
.segment "CODE"
.org $271F
map_control_0f271f:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
