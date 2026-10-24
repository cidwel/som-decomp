.setcpu "65816"
.segment "CODE"
.org $843E
map_control_0d843e:
    .byte $E0 ; previous-row copy escape
    .byte $D7 ; row-distance/count
