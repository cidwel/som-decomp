.setcpu "65816"
.segment "CODE"
.org $9169
map_control_0d9169:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
