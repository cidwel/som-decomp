.setcpu "65816"
.segment "CODE"
.org $BA06
map_control_0dba06:
    .byte $E4 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
