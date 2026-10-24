.setcpu "65816"
.segment "CODE"
.org $E617
map_control_0de617:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
