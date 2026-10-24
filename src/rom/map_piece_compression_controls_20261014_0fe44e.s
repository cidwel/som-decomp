.setcpu "65816"
.segment "CODE"
.org $E44E
map_control_0fe44e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
