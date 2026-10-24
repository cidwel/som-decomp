.setcpu "65816"
.segment "CODE"
.org $4F81
map_control_0f4f81:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
