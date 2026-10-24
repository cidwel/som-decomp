.setcpu "65816"
.segment "CODE"
.org $4C3A
map_control_0f4c3a:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
