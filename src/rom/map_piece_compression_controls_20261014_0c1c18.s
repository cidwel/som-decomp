.setcpu "65816"
.segment "CODE"
.org $1C18
map_control_0c1c18:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
