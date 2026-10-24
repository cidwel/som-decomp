.setcpu "65816"
.segment "CODE"
.org $06D7
map_control_0f06d7:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
