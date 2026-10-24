.setcpu "65816"
.segment "CODE"
.org $9B14
map_control_0f9b14:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
