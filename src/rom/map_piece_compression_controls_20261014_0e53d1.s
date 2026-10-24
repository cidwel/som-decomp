.setcpu "65816"
.segment "CODE"
.org $53D1
map_control_0e53d1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
