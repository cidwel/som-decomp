.setcpu "65816"
.segment "CODE"
.org $D269
map_control_0dd269:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
