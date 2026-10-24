.setcpu "65816"
.segment "CODE"
.org $387B
map_control_0e387b:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
