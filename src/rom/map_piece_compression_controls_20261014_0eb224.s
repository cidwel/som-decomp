.setcpu "65816"
.segment "CODE"
.org $B224
map_control_0eb224:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
