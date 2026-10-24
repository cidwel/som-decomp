.setcpu "65816"
.segment "CODE"
.org $89DD
map_control_0c89dd:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
