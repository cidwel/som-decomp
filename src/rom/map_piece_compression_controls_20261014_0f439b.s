.setcpu "65816"
.segment "CODE"
.org $439B
map_control_0f439b:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
