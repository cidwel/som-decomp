.setcpu "65816"
.segment "CODE"
.org $65C3
map_control_0d65c3:
    .byte $E0 ; previous-row copy escape
    .byte $C2 ; row-distance/count
