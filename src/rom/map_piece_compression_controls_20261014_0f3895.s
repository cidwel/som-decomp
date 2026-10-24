.setcpu "65816"
.segment "CODE"
.org $3895
map_control_0f3895:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
