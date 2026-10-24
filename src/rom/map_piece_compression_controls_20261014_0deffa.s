.setcpu "65816"
.segment "CODE"
.org $EFFA
map_control_0deffa:
    .byte $CF ; same-value copy count/distance
