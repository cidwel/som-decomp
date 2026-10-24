.setcpu "65816"
.segment "CODE"
.org $D3C3
map_control_0ed3c3:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
