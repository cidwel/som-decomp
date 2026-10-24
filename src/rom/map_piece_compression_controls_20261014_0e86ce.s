.setcpu "65816"
.segment "CODE"
.org $86CE
map_control_0e86ce:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
