.setcpu "65816"
.segment "CODE"
.org $DD26
map_control_0edd26:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
