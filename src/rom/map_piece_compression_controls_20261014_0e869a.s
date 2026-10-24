.setcpu "65816"
.segment "CODE"
.org $869A
map_control_0e869a:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
