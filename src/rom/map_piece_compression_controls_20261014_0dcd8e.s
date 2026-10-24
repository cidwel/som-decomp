.setcpu "65816"
.segment "CODE"
.org $CD8E
map_control_0dcd8e:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
