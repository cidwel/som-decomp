.setcpu "65816"
.segment "CODE"
.org $42F5
map_control_0d42f5:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
