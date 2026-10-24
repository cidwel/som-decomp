.setcpu "65816"
.segment "CODE"
.org $AD02
map_control_0fad02:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
