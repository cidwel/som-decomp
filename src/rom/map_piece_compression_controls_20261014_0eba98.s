.setcpu "65816"
.segment "CODE"
.org $BA98
map_control_0eba98:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
