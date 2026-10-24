.setcpu "65816"
.segment "CODE"
.org $6792
map_control_0c6792:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
