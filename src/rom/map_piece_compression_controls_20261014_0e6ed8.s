.setcpu "65816"
.segment "CODE"
.org $6ED8
map_control_0e6ed8:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
