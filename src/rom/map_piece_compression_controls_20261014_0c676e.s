.setcpu "65816"
.segment "CODE"
.org $676E
map_control_0c676e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
