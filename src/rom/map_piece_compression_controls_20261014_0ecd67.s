.setcpu "65816"
.segment "CODE"
.org $CD67
map_control_0ecd67:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
