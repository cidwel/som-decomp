.setcpu "65816"
.segment "CODE"
.org $26F5
map_control_0f26f5:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
