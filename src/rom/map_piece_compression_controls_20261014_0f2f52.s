.setcpu "65816"
.segment "CODE"
.org $2F52
map_control_0f2f52:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
