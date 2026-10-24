.setcpu "65816"
.segment "CODE"
.org $1ACE
map_control_0f1ace:
    .byte $CF ; same-value copy count/distance
