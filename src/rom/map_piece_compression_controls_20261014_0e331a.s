.setcpu "65816"
.segment "CODE"
.org $331A
map_control_0e331a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
