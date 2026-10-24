.setcpu "65816"
.segment "CODE"
.org $A4F1
map_control_0ea4f1:
    .byte $D9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
