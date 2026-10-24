.setcpu "65816"
.segment "CODE"
.org $3168
map_control_0f3168:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
