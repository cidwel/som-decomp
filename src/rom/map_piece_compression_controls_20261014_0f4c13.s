.setcpu "65816"
.segment "CODE"
.org $4C13
map_control_0f4c13:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
