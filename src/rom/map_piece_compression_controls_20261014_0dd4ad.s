.setcpu "65816"
.segment "CODE"
.org $D4AD
map_control_0dd4ad:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
