.setcpu "65816"
.segment "CODE"
.org $4605
map_control_0f4605:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
