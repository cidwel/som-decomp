.setcpu "65816"
.segment "CODE"
.org $183E
map_control_0f183e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
