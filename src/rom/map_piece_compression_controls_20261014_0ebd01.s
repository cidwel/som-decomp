.setcpu "65816"
.segment "CODE"
.org $BD01
map_control_0ebd01:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
