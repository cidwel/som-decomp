.setcpu "65816"
.segment "CODE"
.org $68BB
map_control_0f68bb:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
