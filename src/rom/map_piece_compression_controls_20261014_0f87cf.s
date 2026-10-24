.setcpu "65816"
.segment "CODE"
.org $87CF
map_control_0f87cf:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
