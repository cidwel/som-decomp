.setcpu "65816"
.segment "CODE"
.org $14DB
map_control_0d14db:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
