.setcpu "65816"
.segment "CODE"
.org $8A94
map_control_0f8a94:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
