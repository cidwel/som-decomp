.setcpu "65816"
.segment "CODE"
.org $4DCC
map_control_0f4dcc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
