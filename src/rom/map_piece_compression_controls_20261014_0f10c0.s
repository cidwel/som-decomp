.setcpu "65816"
.segment "CODE"
.org $10C0
map_control_0f10c0:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
