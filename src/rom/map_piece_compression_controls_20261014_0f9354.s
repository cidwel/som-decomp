.setcpu "65816"
.segment "CODE"
.org $9354
map_control_0f9354:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
