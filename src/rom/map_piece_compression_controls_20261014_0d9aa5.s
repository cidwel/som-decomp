.setcpu "65816"
.segment "CODE"
.org $9AA5
map_control_0d9aa5:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
