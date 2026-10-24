.setcpu "65816"
.segment "CODE"
.org $9A11
map_control_0f9a11:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
