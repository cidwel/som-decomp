.setcpu "65816"
.segment "CODE"
.org $18EB
map_control_0f18eb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
