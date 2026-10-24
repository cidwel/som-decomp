.setcpu "65816"
.segment "CODE"
.org $4E47
map_control_0f4e47:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
