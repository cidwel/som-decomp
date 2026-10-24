.setcpu "65816"
.segment "CODE"
.org $0D4A
map_control_0c0d4a:
    .byte $CF ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
