.setcpu "65816"
.segment "CODE"
.org $8B9B
map_control_0c8b9b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
