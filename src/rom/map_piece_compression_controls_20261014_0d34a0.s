.setcpu "65816"
.segment "CODE"
.org $34A0
map_control_0d34a0:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
