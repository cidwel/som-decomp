.setcpu "65816"
.segment "CODE"
.org $9D60
map_control_0f9d60:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
