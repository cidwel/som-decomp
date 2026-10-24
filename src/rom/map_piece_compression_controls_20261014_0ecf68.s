.setcpu "65816"
.segment "CODE"
.org $CF68
map_control_0ecf68:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
