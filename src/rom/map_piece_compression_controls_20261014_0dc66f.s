.setcpu "65816"
.segment "CODE"
.org $C66F
map_control_0dc66f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
