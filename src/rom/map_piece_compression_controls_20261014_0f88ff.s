.setcpu "65816"
.segment "CODE"
.org $88FF
map_control_0f88ff:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
