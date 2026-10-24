.setcpu "65816"
.segment "CODE"
.org $4DAF
map_control_0d4daf:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
