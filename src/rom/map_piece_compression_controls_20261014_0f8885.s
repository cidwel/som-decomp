.setcpu "65816"
.segment "CODE"
.org $8885
map_control_0f8885:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
