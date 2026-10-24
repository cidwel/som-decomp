.setcpu "65816"
.segment "CODE"
.org $2B62
map_control_0f2b62:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
