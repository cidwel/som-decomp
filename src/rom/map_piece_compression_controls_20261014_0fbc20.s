.setcpu "65816"
.segment "CODE"
.org $BC20
map_control_0fbc20:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
