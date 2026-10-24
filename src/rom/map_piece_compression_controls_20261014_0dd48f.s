.setcpu "65816"
.segment "CODE"
.org $D48F
map_control_0dd48f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
