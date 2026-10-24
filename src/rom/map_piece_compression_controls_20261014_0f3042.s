.setcpu "65816"
.segment "CODE"
.org $3042
map_control_0f3042:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
