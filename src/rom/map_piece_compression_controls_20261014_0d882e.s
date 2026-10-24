.setcpu "65816"
.segment "CODE"
.org $882E
map_control_0d882e:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
