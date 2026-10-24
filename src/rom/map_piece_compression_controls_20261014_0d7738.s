.setcpu "65816"
.segment "CODE"
.org $7738
map_control_0d7738:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
