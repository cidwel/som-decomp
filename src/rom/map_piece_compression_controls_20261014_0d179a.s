.setcpu "65816"
.segment "CODE"
.org $179A
map_control_0d179a:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
