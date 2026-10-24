.setcpu "65816"
.segment "CODE"
.org $7370
map_control_0c7370:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
