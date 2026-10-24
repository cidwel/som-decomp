.setcpu "65816"
.segment "CODE"
.org $CC98
map_control_0ecc98:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
