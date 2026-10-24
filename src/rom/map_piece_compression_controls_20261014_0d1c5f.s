.setcpu "65816"
.segment "CODE"
.org $1C5F
map_control_0d1c5f:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
