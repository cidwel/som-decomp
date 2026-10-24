.setcpu "65816"
.segment "CODE"
.org $46D5
map_control_0d46d5:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
