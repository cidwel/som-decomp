.setcpu "65816"
.segment "CODE"
.org $ABB8
map_control_0fabb8:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
