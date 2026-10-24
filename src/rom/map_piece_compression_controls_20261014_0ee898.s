.setcpu "65816"
.segment "CODE"
.org $E898
map_control_0ee898:
    .byte $E4 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
