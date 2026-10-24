.setcpu "65816"
.segment "CODE"
.org $88FF
map_control_0e88ff:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
