.setcpu "65816"
.segment "CODE"
.org $1FD6
map_control_0e1fd6:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
