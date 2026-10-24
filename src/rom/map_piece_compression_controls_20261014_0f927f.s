.setcpu "65816"
.segment "CODE"
.org $927F
map_control_0f927f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
