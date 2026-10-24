.setcpu "65816"
.segment "CODE"
.org $0236
map_control_0e0236:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
