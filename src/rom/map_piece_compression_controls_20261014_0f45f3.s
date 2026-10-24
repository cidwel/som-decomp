.setcpu "65816"
.segment "CODE"
.org $45F3
map_control_0f45f3:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
