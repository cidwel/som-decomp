.setcpu "65816"
.segment "CODE"
.org $103C
map_control_0c103c:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
