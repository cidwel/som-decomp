.setcpu "65816"
.segment "CODE"
.org $386E
map_control_0f386e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
