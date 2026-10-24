.setcpu "65816"
.segment "CODE"
.org $74AC
map_control_0f74ac:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
