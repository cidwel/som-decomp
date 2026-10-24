.setcpu "65816"
.segment "CODE"
.org $307A
map_control_0f307a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
