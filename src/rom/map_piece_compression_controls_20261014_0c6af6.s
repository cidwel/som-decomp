.setcpu "65816"
.segment "CODE"
.org $6AF6
map_control_0c6af6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
