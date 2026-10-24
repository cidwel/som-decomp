.setcpu "65816"
.segment "CODE"
.org $0563
map_control_0f0563:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
