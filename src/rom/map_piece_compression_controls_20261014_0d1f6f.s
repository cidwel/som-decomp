.setcpu "65816"
.segment "CODE"
.org $1F6F
map_control_0d1f6f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
