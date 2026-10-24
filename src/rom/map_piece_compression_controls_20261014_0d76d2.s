.setcpu "65816"
.segment "CODE"
.org $76D2
map_control_0d76d2:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
