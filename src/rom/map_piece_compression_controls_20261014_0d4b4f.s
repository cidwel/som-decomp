.setcpu "65816"
.segment "CODE"
.org $4B4F
map_control_0d4b4f:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
