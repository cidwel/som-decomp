.setcpu "65816"
.segment "CODE"
.org $32F9
map_control_0e32f9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
