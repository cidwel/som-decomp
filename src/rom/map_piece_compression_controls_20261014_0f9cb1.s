.setcpu "65816"
.segment "CODE"
.org $9CB1
map_control_0f9cb1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
