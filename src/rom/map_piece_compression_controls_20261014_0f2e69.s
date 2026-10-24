.setcpu "65816"
.segment "CODE"
.org $2E69
map_control_0f2e69:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
