.setcpu "65816"
.segment "CODE"
.org $8F41
map_control_0f8f41:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
