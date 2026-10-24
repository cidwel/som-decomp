.setcpu "65816"
.segment "CODE"
.org $7226
map_control_0f7226:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
