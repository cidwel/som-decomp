.setcpu "65816"
.segment "CODE"
.org $1FD3
map_control_0e1fd3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
