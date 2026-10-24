.setcpu "65816"
.segment "CODE"
.org $90A5
map_control_0f90a5:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
