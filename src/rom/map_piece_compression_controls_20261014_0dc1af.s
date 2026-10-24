.setcpu "65816"
.segment "CODE"
.org $C1AF
map_control_0dc1af:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
