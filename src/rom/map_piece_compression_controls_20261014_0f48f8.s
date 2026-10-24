.setcpu "65816"
.segment "CODE"
.org $48F8
map_control_0f48f8:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
