.setcpu "65816"
.segment "CODE"
.org $AFBD
map_control_0dafbd:
    .byte $CF ; same-value copy count/distance
