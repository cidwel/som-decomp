.setcpu "65816"
.segment "CODE"
.org $FC0F
map_control_0ffc0f:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
