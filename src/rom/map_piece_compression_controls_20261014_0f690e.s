.setcpu "65816"
.segment "CODE"
.org $690E
map_control_0f690e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
