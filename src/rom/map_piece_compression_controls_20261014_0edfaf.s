.setcpu "65816"
.segment "CODE"
.org $DFAF
map_control_0edfaf:
    .byte $CB ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
