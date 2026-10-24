.setcpu "65816"
.segment "CODE"
.org $099B
map_control_0e099b:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
