.setcpu "65816"
.segment "CODE"
.org $332E
map_control_0f332e:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E6 ; previous-row copy count
