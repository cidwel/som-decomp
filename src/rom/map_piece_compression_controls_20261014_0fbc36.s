.setcpu "65816"
.segment "CODE"
.org $BC36
map_control_0fbc36:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
