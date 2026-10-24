.setcpu "65816"
.segment "CODE"
.org $A105
map_control_0fa105:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
