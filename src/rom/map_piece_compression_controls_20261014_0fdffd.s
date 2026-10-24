.setcpu "65816"
.segment "CODE"
.org $DFFD
map_control_0fdffd:
    .byte $C3 ; same-value copy count/distance
