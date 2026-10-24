.setcpu "65816"
.segment "CODE"
.org $1C1E
map_control_0c1c1e:
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
