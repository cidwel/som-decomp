.setcpu "65816"
.segment "CODE"
.org $65D8
map_control_0f65d8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
