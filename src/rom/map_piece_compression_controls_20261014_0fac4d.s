.setcpu "65816"
.segment "CODE"
.org $AC4D
map_control_0fac4d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
