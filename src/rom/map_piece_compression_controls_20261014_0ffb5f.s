.setcpu "65816"
.segment "CODE"
.org $FB5F
map_control_0ffb5f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
