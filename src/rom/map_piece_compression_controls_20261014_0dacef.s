.setcpu "65816"
.segment "CODE"
.org $ACEF
map_control_0dacef:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
