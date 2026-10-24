.setcpu "65816"
.segment "CODE"
.org $9F25
map_control_0f9f25:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
