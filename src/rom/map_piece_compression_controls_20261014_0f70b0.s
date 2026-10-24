.setcpu "65816"
.segment "CODE"
.org $70B0
map_control_0f70b0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
