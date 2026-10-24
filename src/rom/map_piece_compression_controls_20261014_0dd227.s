.setcpu "65816"
.segment "CODE"
.org $D227
map_control_0dd227:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
