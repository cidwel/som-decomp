.setcpu "65816"
.segment "CODE"
.org $F1FD
map_control_0df1fd:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
