.setcpu "65816"
.segment "CODE"
.org $943E
map_control_0d943e:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
