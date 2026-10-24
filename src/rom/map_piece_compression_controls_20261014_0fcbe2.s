.setcpu "65816"
.segment "CODE"
.org $CBE2
map_control_0fcbe2:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
