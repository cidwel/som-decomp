.setcpu "65816"
.segment "CODE"
.org $3150
map_control_0f3150:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
