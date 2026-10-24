.setcpu "65816"
.segment "CODE"
.org $90FA
map_control_0f90fa:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
