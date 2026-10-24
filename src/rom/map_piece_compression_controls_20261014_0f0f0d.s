.setcpu "65816"
.segment "CODE"
.org $0F0D
map_control_0f0f0d:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
