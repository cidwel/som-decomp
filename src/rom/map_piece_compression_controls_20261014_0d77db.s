.setcpu "65816"
.segment "CODE"
.org $77DB
map_control_0d77db:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
