.setcpu "65816"
.segment "CODE"
.org $2918
map_control_0f2918:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
