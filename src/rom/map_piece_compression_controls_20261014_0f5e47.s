.setcpu "65816"
.segment "CODE"
.org $5E47
map_control_0f5e47:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
