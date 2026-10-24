.setcpu "65816"
.segment "CODE"
.org $B366
map_control_0fb366:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
