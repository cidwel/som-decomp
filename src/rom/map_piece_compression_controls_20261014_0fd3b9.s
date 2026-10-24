.setcpu "65816"
.segment "CODE"
.org $D3B9
map_control_0fd3b9:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
