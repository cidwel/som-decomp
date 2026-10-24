.setcpu "65816"
.segment "CODE"
.org $D3C9
map_control_0ed3c9:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
