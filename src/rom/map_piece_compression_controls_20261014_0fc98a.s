.setcpu "65816"
.segment "CODE"
.org $C98A
map_control_0fc98a:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
