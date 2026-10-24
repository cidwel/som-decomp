.setcpu "65816"
.segment "CODE"
.org $D41E
map_control_0ed41e:
    .byte $E0 ; previous-row copy escape
    .byte $CD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $64 ; row-distance/count
