.setcpu "65816"
.segment "CODE"
.org $5E37
map_control_0f5e37:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
