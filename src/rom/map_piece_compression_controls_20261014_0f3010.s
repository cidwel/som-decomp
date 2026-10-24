.setcpu "65816"
.segment "CODE"
.org $3010
map_control_0f3010:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
