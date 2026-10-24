.setcpu "65816"
.segment "CODE"
.org $224E
map_control_0d224e:
    .byte $CB ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
