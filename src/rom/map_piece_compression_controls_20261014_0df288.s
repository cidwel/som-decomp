.setcpu "65816"
.segment "CODE"
.org $F288
map_control_0df288:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
