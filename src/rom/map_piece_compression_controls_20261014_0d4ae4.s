.setcpu "65816"
.segment "CODE"
.org $4AE4
map_control_0d4ae4:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
