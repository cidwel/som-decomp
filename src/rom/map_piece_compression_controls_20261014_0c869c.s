.setcpu "65816"
.segment "CODE"
.org $869C
map_control_0c869c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
