.setcpu "65816"
.segment "CODE"
.org $645B
map_control_0f645b:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
