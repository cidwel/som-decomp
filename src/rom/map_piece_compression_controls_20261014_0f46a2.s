.setcpu "65816"
.segment "CODE"
.org $46A2
map_control_0f46a2:
    .byte $E0 ; previous-row copy escape
    .byte $58 ; row-distance/count
