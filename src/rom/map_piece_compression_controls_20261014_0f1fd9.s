.setcpu "65816"
.segment "CODE"
.org $1FD9
map_control_0f1fd9:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
