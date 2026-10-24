.setcpu "65816"
.segment "CODE"
.org $42DF
map_control_0e42df:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
