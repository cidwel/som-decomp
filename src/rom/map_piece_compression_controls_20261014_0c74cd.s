.setcpu "65816"
.segment "CODE"
.org $74CD
map_control_0c74cd:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
