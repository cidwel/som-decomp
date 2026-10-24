.setcpu "65816"
.segment "CODE"
.org $1FD5
map_control_0f1fd5:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
