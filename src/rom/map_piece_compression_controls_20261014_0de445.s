.setcpu "65816"
.segment "CODE"
.org $E445
map_control_0de445:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
