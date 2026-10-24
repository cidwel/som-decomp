.setcpu "65816"
.segment "CODE"
.org $21A0
map_control_0f21a0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
