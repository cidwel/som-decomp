.setcpu "65816"
.segment "CODE"
.org $9B31
map_control_0e9b31:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
