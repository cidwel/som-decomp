.setcpu "65816"
.segment "CODE"
.org $48A7
map_control_0f48a7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
