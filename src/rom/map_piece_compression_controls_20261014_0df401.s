.setcpu "65816"
.segment "CODE"
.org $F401
map_control_0df401:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
