.setcpu "65816"
.segment "CODE"
.org $DC6A
map_control_0fdc6a:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
