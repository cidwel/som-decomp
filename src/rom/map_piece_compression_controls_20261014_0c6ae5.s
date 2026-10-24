.setcpu "65816"
.segment "CODE"
.org $6AE5
map_control_0c6ae5:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
