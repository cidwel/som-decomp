.setcpu "65816"
.segment "CODE"
.org $C11E
map_control_0ec11e:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
