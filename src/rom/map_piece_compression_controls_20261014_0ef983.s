.setcpu "65816"
.segment "CODE"
.org $F983
map_control_0ef983:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
