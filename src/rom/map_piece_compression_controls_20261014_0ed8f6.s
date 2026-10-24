.setcpu "65816"
.segment "CODE"
.org $D8F6
map_control_0ed8f6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
