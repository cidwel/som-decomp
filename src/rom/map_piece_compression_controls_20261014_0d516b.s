.setcpu "65816"
.segment "CODE"
.org $516B
map_control_0d516b:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
