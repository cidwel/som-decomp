.setcpu "65816"
.segment "CODE"
.org $B35F
map_control_0fb35f:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
