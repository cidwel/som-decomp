.setcpu "65816"
.segment "CODE"
.org $C99E
map_control_0ec99e:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
