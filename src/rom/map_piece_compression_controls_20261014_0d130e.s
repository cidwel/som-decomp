.setcpu "65816"
.segment "CODE"
.org $130E
map_control_0d130e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
