.setcpu "65816"
.segment "CODE"
.org $5F84
map_control_0e5f84:
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
