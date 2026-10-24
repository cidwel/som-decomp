.setcpu "65816"
.segment "CODE"
.org $B257
map_control_0fb257:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
