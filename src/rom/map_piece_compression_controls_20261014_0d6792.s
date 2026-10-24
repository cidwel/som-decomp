.setcpu "65816"
.segment "CODE"
.org $6792
map_control_0d6792:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
