.setcpu "65816"
.segment "CODE"
.org $A752
map_control_0ea752:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
