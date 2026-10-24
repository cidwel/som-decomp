.setcpu "65816"
.segment "CODE"
.org $804A
map_control_0e804a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
