.setcpu "65816"
.segment "CODE"
.org $336A
map_control_0f336a:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
