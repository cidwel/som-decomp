.setcpu "65816"
.segment "CODE"
.org $4A7A
map_control_0f4a7a:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
