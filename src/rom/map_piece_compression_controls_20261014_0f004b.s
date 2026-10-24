.setcpu "65816"
.segment "CODE"
.org $004B
map_control_0f004b:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
