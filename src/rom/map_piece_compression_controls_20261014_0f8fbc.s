.setcpu "65816"
.segment "CODE"
.org $8FBC
map_control_0f8fbc:
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
