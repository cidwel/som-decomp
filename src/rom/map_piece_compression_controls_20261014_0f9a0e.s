.setcpu "65816"
.segment "CODE"
.org $9A0E
map_control_0f9a0e:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
