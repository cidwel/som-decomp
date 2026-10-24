.setcpu "65816"
.segment "CODE"
.org $143E
map_control_0c143e:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
