.setcpu "65816"
.segment "CODE"
.org $F598
map_control_0ff598:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
