.setcpu "65816"
.segment "CODE"
.org $50EC
map_control_0f50ec:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
