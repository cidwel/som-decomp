.setcpu "65816"
.segment "CODE"
.org $0450
map_control_0e0450:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
