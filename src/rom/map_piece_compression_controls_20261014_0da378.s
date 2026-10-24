.setcpu "65816"
.segment "CODE"
.org $A378
map_control_0da378:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
