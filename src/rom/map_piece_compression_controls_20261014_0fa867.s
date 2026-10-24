.setcpu "65816"
.segment "CODE"
.org $A867
map_control_0fa867:
    .byte $CC ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
