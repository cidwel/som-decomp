.setcpu "65816"
.segment "CODE"
.org $05CF
map_control_0f05cf:
    .byte $DB ; same-value copy count/distance
