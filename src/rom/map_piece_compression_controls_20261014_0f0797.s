.setcpu "65816"
.segment "CODE"
.org $0797
map_control_0f0797:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
