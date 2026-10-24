.setcpu "65816"
.segment "CODE"
.org $819C
map_control_0f819c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
