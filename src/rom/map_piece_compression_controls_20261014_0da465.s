.setcpu "65816"
.segment "CODE"
.org $A465
map_control_0da465:
    .byte $E2 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
