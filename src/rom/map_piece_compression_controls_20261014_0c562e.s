.setcpu "65816"
.segment "CODE"
.org $562E
map_control_0c562e:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
