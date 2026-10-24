.setcpu "65816"
.segment "CODE"
.org $2738
map_control_0f2738:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
