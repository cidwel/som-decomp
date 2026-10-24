.setcpu "65816"
.segment "CODE"
.org $F0BF
map_control_0ff0bf:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
