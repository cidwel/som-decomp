.setcpu "65816"
.segment "CODE"
.org $740F
map_control_0f740f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
