.setcpu "65816"
.segment "CODE"
.org $050A
map_control_0e050a:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
