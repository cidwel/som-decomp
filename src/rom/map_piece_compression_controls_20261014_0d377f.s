.setcpu "65816"
.segment "CODE"
.org $377F
map_control_0d377f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
