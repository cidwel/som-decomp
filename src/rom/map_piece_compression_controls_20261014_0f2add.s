.setcpu "65816"
.segment "CODE"
.org $2ADD
map_control_0f2add:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
