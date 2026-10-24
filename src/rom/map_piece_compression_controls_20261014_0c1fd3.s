.setcpu "65816"
.segment "CODE"
.org $1FD3
map_control_0c1fd3:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
